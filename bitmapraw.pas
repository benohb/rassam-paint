unit Bitmapraw;

{$mode objfpc}


interface
uses
  SysUtils, Classes,cairo,gdk2,Graphics;


 Type
  PLaye=^Laye;
  Laye = Record
    FC:Pcairo_surface_t;
    PL:Pcairo_pattern_t;
    CR:Pcairo_t ;
    step:integer;
  end;

 // Undo = array [0..17] of Laye;

  Mov = Record
    XFixDown:TPoint;
    XmovReal:TPoint;

    BFixDown:TPoint;
    BmovReal:TPoint;
    BDiff   :TPoint;
  end;

  type
  PTFastRGBA= ^TFastRGBA;
  TFastRGBA =  record
  Blue: Byte;
  Green: Byte;
  red: Byte;
  Alpha: Byte;
  end;


  type
  PTRGBA= ^TRGBA;
  TRGBA =  record
  red: Byte;
  Green: Byte;
  Blue: Byte;
  Alpha: Byte;

end;





  mode = Record
     mode:string;
    colorA:TRGBA;
    colorB:TRGBA;
    lineW:integer;
    line_full:integer;
    alpha :integer;
    anti  :Boolean;
    fullback :Boolean;
    cut :Boolean;
    key: Word;
    picoloshow :integer;
  end;




  ByteRA = array [1..1] of byte;
  Bytep = ^ByteRA;
  LongIntRA = array [1..1] of LongInt;
  LongIntp = ^LongIntRA;


procedure FloodFillX (X, Y: Integer;FSize:TPoint;color_New:Longword;Data:PLongword);
procedure Floodcolorall (points,FSize:TPoint;color_New:Longword;Data:Pchar);
procedure clearbackcolor (FSize:TPoint;color_New:Longword;Data:Pchar;onn:Boolean);
procedure clearsel_A (FSize:TPoint;Data:Pchar;onn:Boolean);
function GetTcolor (pos,FSize:TPoint;Data:Pchar):Tcolor;

implementation

procedure FloodFillX (X, Y: Integer;FSize:TPoint;color_New:Longword;Data:PLongword);
//Written by Chris Rorden
//A simple first-in-first-out circular buffer (the queue) for flood-filling contiguous voxels.
//This algorithm avoids stack problems associated simple recursive algorithms
//http://steve.hollasch.net/cgindex/polygons/floodfill.html
const
     kFill = 0; //pixels we will want to flood fill
     kFillable = 128; //voxels we might flood fill
     kUnfillable = 255; //voxels we can not flood fill
var
  lWid,lHt,lQSz,lQHead,lQTail: integer;
  lQRA: LongIntP;
  lMaskRA: ByteP;
  mxx,mnx:integer;
  color_OLD :Longword;

function GetPixelcolor(X, Y: Longint): PLongword;
begin

  Result := @Data[(Y * FSize.X) + X] ;

end;

procedure IncQra(var lVal, lQSz: integer);inline;//nested inside FloodFill
begin
    inc(lVal);
    if lVal >= lQSz then
       lVal := 1;
end; //nested Proc IncQra
function Pos2XY (lPos: integer): TPoint;inline;
begin
    result.X := ((lPos-1) mod lWid)+1; //horizontal position
    result.Y := ((lPos-1) div lWid)+1; //vertical position
end; //nested Proc Pos2XY
procedure TestPixel(lPos: integer);inline;
begin
     if (lMaskRA^[lPos]=kFillable) then begin
        lMaskRA^[lPos] := kFill;
        lQra^[lQHead] := lPos;
        incQra(lQHead,lQSz);
     end;
end; //nested Proc TestPixel
procedure RetirePixel;inline; //nested inside FloodFill
var
   lVal: integer;
   lXY : TPoint;
begin
   lVal := lQra^[lQTail];
   lXY := Pos2XY(lVal);
   if lXY.Y > 1 then
        TestPixel (lVal-lWid);//pixel above
   if lXY.Y < lHt then
      TestPixel (lVal+lWid);//pixel below
   if lXY.X > 1 then
        TestPixel (lVal-1); //pixel to left
   if lXY.X < lWid then
      TestPixel (lVal+1); //pixel to right



   incQra(lQTail,lQSz); //done with this pixel
end; //nested proc RetirePixel
var
   lTargetColorVal,lDefaultVal: byte;
   lX,lY,lPos: integer;
   lBrushColor: Longword;

begin //FloodFill
     color_OLD:=GetPixelcolor(x,y)^;
     if color_New = color_OLD then exit;
     lTargetColorVal := kFillable;
     lDefaultVal := kUnfillable;

  //if (lPt < 1) or (lPt > lMaskSz) or (lMaskP[lPt] <> 128) then exit;
  lHt := FSize.Y;
  lWid := FSize.X;
  mnx:=FSize.X;
  lQSz := lHt * lWid;
  //Qsz should be more than the most possible simultaneously active pixels
  //Worst case scenario is a click at the center of a 3x3 image: all 9 pixels will be active simultaneously
  //for larger images, only a tiny fraction of pixels will be active at one instance.
  //perhaps lQSz = ((lHt*lWid) div 4) + 32; would be safe and more memory efficient
  if (lHt < 1) or (lWid < 1) then exit;
  getmem(lQra,lQSz*sizeof(longint)); //very wasteful -
  getmem(lMaskRA,lHt*lWid*sizeof(byte));
  for lPos := 1 to (lHt*lWid) do
      lMaskRA^[lPos] := lDefaultVal; //assume all voxels are non targets
  lPos := 0;
  for lY := 0 to (lHt-1) do
      for lX := 0 to (lWid-1) do begin
          lPos := lPos + 1;
          if GetPixelcolor(lX,lY)^ = color_OLD then
             lMaskRA^[lPos] := lTargetColorVal;
      end;
  lQHead := 2;
  lQTail := 1;
  lQra^[lQTail] := ((Y * lWid)+X+1); //NOTE: both X and Y start from 0 not 1
  lMaskRA^[lQra^[lQTail]] := kFill;
  RetirePixel;


  while lQHead <> lQTail do
        RetirePixel;


  lPos := 0;
  for lY := 0 to (lHt-1) do
      for lX := 0 to (lWid-1) do begin
          lPos := lPos + 1;
          if lMaskRA^[lPos] = kFill then
             GetPixelcolor(lX,lY)^ := color_New;
      end;
  freemem(lMaskRA);
  freemem(lQra);





end;//
procedure Floodcolorall (points,FSize:TPoint;color_New:Longword;Data:Pchar);
var
   po: integer;
   coll: Longword;

begin

      inc(Data,((FSize.x * points.y) + points.X )*4);
       coll := PLongword(Data)^;
      inc(Data,-((FSize.x * points.y) + points.X )*4);


      for po := 0 to (FSize.Y*FSize.X) do
      begin
      if PLongword(Data)^=coll then PLongword(Data)^:=color_New ;

      inc(Data,4);

     end;



end;
procedure clearbackcolor (FSize:TPoint;color_New:Longword;Data:Pchar;onn:Boolean);

var
   po: integer;
begin


      for po := 0 to (FSize.Y*FSize.X)-1 do
      begin

           if onn then
           begin
            if PLongword(Data)^=color_New then PLongword(Data)^:=$00000000 ;
            end else begin
            if PLongword(Data)^=$00000000 then PLongword(Data)^:=color_New ;
           end;


        inc(Data,4);

    end;




end;
procedure clearsel_A (FSize:TPoint;Data:Pchar;onn:Boolean);
var
   po: integer;
begin


      for po := 0 to (FSize.Y)*(FSize.X)-1 do
      begin

         if onn then begin
         if PTFastRGBA(Data)^.Alpha =0 then PTFastRGBA(Data)^.Alpha :=1  ;
          end else begin
         if PTFastRGBA(Data)^.Alpha =1 then PTFastRGBA(Data)^.Alpha :=0  ;

         end;
         inc(Data,4);

      end;


end;
function GetTcolor (pos,FSize:TPoint;Data:Pchar):Tcolor;
var
   po: integer;
   rgT:TRGBA;

begin


     inc(Data,((FSize.x * pos.y) + pos.X )*4);

      rgT.red:=PTFastRGBA(Data)^.red;
      rgT.Green:=PTFastRGBA(Data)^.Green;
      rgT.Blue:=PTFastRGBA(Data)^.Blue;
      rgT.Alpha:=0;
      GetTcolor:=Longword(rgT);


end;


end.

