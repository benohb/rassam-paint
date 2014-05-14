unit Unit2;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Controls, Graphics,StdCtrls,Forms
  ,gtk2int, gtk2, glib2, gdk2x, Gdk2, gdk2pixbuf,Clipbrd,
  gtk2def, WSLCLClasses,ExtCtrls,
  cairo,LCLType,LCLIntf,Bitmapraw,FPimage,math,LResources
  ,pangocairo,pango,Unit3
  ,intfgraphics,printV;//,Printers;




Type
Styppoint = Array of TPoint;

 Sel = Record
        Ssize   :TPoint;
        Spos   :TPoint;
    end;


 procedure getur(clipboard:PGtkClipboard; selection_data:PGtkSelectionData; data:gpointer);





type
  TDrawingControl = class(TCustomControl)
  public
    filename:string;
    modf:Boolean ;
    DeviceC: TGtkDeviceContext;
    aWidth, aHeight: Integer;

    Bmpw,Bmph,curc:integer;
    zoom:byte;
    VUndo:byte;
    Vmode : mode;
    Scol_V:^TScrollBar;
    Scol_H:^TScrollBar;
    IdleTimer1: TIdleTimer;

     Lsx,Ls0,Lstmp:Laye;
     bt:TBitmap;
     Tundo:array of Laye;
     TmpRender: TNotifyEvent;

     TmpStart :procedure()of object;

     SelRect : Trect;
     SelPon  : Array[1..8]   of Tpoint;
     PageRect : Array[0..5] of Tpoint;
     MR,MM,ML,RF,mSH,mCT : byte;

     VMov:Mov;
     Vsel:Sel;

     Picture:TPicture;
     ArraySel:Styppoint;
     Sl_rect:Trect;


     layout:PPangoLayout ;
     desc:PPangoFontDescription;





  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;

    procedure Paint; override;
    procedure intt();
    procedure FromDC();
    procedure SurfrSETDC();

    procedure Resizeo(Sender: TObject);



    procedure make_new(Lay:PLaye;x,y:integer);
    procedure make_new_ph(x,y:integer);
    procedure make_load(Path:string);
    procedure make_save(Path:string);
    procedure make_print(Path:string);


    procedure make_destroy(Lay:PLaye);

    function  undo_get_next():byte;
    function  undo_get_back():byte;
    procedure page_undo();
    procedure page_redo();
    procedure page_unext();
    procedure page_Backro();

    procedure Clipboard_set();
    procedure Clipboard_get();

    function BtoSXX(xv:integer):integer;
    function BtoSYY(Yv:integer):integer;


    //page////////////////////////////////////////////////////////
    procedure page_start();
    procedure page_end();
    procedure page_Render(Sender: TObject);
    procedure page_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure page_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure page_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure page_Mouse_IN ();
    procedure page_resz ();
    procedure Glob_Getsize();

    //draw
    procedure DrawS_start();
    procedure DrawS_Render(Sender: TObject);
    procedure DrawS_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure DrawS_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure DrawS_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure DrawS_ok ();
    //recsel
    procedure selrect_start();
    procedure selrect_Render(Sender: TObject);
    procedure selrect_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure selrect_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure selrect_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure selrect_ok ();
    //movob
    procedure MooB_Start();
    procedure MooB_Render(Sender: TObject);
    procedure MooB_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure MooB_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure MooB_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure MooB_Mouse_IN();
    procedure MooB_resz();
    procedure MooB_reGet();
    procedure MooB_ok();
    procedure MooB_clearback();
    procedure MooB_del();

    //Fill
    procedure Fill_start();
    procedure Fill_Render(Sender: TObject);
    procedure Fill_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure Fill_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure Fill_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    //arc
    procedure arc_start();
    procedure arc_Render(Sender: TObject);
    procedure arc_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure arc_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure arc_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    //line
    procedure line_start();
    procedure line_Render(Sender: TObject);
    procedure line_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure line_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure line_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
   //crc
    procedure circ_start();
    procedure circ_Render(Sender: TObject);
    procedure circ_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure circ_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure circ_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure circ_ok();
    //txt
    procedure txt_Start();
    procedure txt_Render(Sender: TObject);
    procedure txt_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure txt_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure txt_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure txt_Mouse_IN();
    procedure txt_resz();
    procedure txt_reGet();
    procedure txt_ok();
    procedure txt_clearback();
    procedure txt_Chang(Sender: TObject);

    //pen

    procedure Pen_start();
    procedure Pen_Render(Sender: TObject);
    procedure Pen_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure Pen_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure Pen_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    //
    //brr
    procedure Brr_start();
    procedure Brr_Render(Sender: TObject);
    procedure Brr_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure Brr_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure Brr_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);

    // recdraw_File.inc
    procedure recdraw_start();
    procedure recdraw_Render(Sender: TObject);
    procedure recdraw_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure recdraw_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure recdraw_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure recdraw_ok();



    //dik

    procedure dik_start();
    procedure dik_Render(Sender: TObject);
    procedure dik_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure dik_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure dik_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);

    //
    procedure mim_start();
    procedure mim_Render(Sender: TObject);
    procedure mim_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
    procedure mim_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
    procedure mim_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);

     //fon
    procedure Fonc_flV(m:Boolean);
    procedure Fonc_swap(m:Boolean);
    procedure Fonc_Shear(m:Double;b:Boolean);
    procedure Fonc_color_inv();
    procedure Fonc_BW();
    procedure test(blo:integer);


  end;

  procedure Pcur();





implementation


uses Unit1;
{$i page_File.inc}
{$i DrawS_File.inc}
{$i selRec_File.inc}
{$i movOb_File.inc}
{$i Fill_File.inc}
{$i arc_File.inc}
{$i line_File.inc}
{$i circ_File.inc}
{$i txt_File.inc}
{$i Pen_File.inc}
{$i brr_File.inc}
{$i recdraw_File.inc }
{$i Fonc_File.inc}
{$i dik_File.inc}
{$i mim_File.inc}


//{$i setup.inc}
constructor TDrawingControl.Create(AOwner: TComponent);

begin
  inherited Create(AOwner);
  SetLength(Tundo,17);

  IdleTimer1:= TIdleTimer.Create(self);
  IdleTimer1.Interval:=20;
  IdleTimer1.Name:='tm1';
  Pcur();
  bt:=tbitmap.Create;
end;

destructor TDrawingControl.Destroy;
begin
  bt.Free;
  inherited Destroy;
end;


procedure TDrawingControl.Resizeo(Sender: TObject);

begin

  rf:=1;
  IdleTimer1.Enabled:=true;


end;


 procedure TDrawingControl.intt();


begin

  make_destroy(@lsX);
  make_destroy(@Ls0);

  FromDC();
  self.OnChangeBounds:=@Resizeo;
  IdleTimer1.Enabled:=false;
  Vmode.lineW:=1;

end;
procedure TDrawingControl.FromDC();

   var bb:Pcairo_t ;

begin
      bt.SetSize(Width,Height);
      DeviceC:=TGtkDeviceContext(bt.Canvas.Handle);
     // gdk_window_get_size(PGdkWindow(DeviceC.Drawable), @aWidth, @aHeight);

      LsX.CR:=gdk_cairo_create(DeviceC.Drawable);



    cairo_set_antialias (LsX.CR ,CAIRO_ANTIALIAS_NONE);

end;

procedure TDrawingControl.SurfrSETDC();
begin
   // zoom:=50;
    if not Assigned(bt) then exit;

    if (bt.Width<>Width) or (bt.Height<>Height) then
    begin
     bt.Free;
     bt:=Tbitmap.Create;
    bt.SetSize(Width,Height);
    DeviceC:=TGtkDeviceContext(bt.Canvas.Handle);


    LsX.CR:=gdk_cairo_create(DeviceC.Drawable);

    cairo_set_antialias (LsX.CR ,CAIRO_ANTIALIAS_NONE);
    end;


    if Tundo[VUndo].FC <> nil then begin
          Bmpw := cairo_image_surface_get_width(Tundo[VUndo].FC);
          Bmph := cairo_image_surface_get_height(Tundo[VUndo].FC);
      end;



    if (Scol_H =nil) or (Bmpw+Bmph=0)  then exit();



        if  (Width div zoom )<Bmpw then Scol_H^.Visible:=true else Scol_H^.Visible:=false ;

        if  (Height div zoom)<Bmph then Scol_V^.Visible:=true else Scol_V^.Visible:=false;

        if  (Width div zoom )<Bmpw then Scol_H^.Visible:=true else Scol_H^.Visible:=false ;



        if Scol_H^.Visible then
        begin
        Scol_H^.Max:=Bmpw-(Width div zoom );
        Scol_H^.Left:=self.Left;
        Scol_H^.Top:=(top+Height)-Scol_H^.Height ;
        Scol_H^.Width:=Width;
        end else begin
        Scol_H^.Max:=0;
        Scol_H^.Position:=0;
        end;

        if Scol_V^.Visible then
        begin
        Scol_V^.Max:=Bmph-(Height div zoom );
        Scol_V^.left:=Width-Scol_V^.Width;
        Scol_V^.Top:=0;
        Scol_V^.Height:=Height;
        end else begin
        Scol_v^.Max:=0;
        Scol_V^.Position:=0;
        end;

        if (Scol_V^.Visible) and (Scol_H^.Visible) then

           Scol_H^.BorderSpacing.Right:=Scol_V^.Width
           else
           Scol_H^.BorderSpacing.Right:=0
        ;


        Scol_H^.Tag:= Scol_H^.Position;
        Scol_v^.Tag:= Scol_v^.Position;



        RF:=1;
        IdleTimer1.Enabled:=true;



end;




procedure TDrawingControl.make_new(Lay:PLaye;x,y:integer);

begin
   make_destroy(Lay);
   Lay^.FC:=cairo_image_surface_create(CAIRO_FORMAT_ARGB32,X,Y);
   Lay^.PL:=cairo_pattern_create_for_surface(Lay^.FC);
   Lay^.CR := cairo_create (Lay^.FC);
   cairo_pattern_set_filter(Lay^.PL,CAIRO_FILTER_FAST);
   cairo_set_antialias(Lay^.CR,CAIRO_ANTIALIAS_NONE);


end;

procedure TDrawingControl.make_new_ph(x,y:integer);
 var loop:integer;
begin

  for loop :=0 to (Length(Tundo)-1) do
  begin

      make_destroy(@Tundo[loop]);
      Tundo[loop].step:=-1;
  end;

   make_new(@Tundo[0],x,y);


   cairo_set_source_rgb(Tundo[0].CR,
   Single(Vmode.colorB.Red)  /255,
   Single(Vmode.colorB.Green)/255,
   Single(Vmode.colorB.Blue) /255);

   cairo_paint(Tundo[0].CR);

   Bmpw := cairo_image_surface_get_width(Tundo[0].FC);
   Bmph := cairo_image_surface_get_height(Tundo[0].FC);
   Tundo[0].step:=0;
   VUndo:=0;
   zoom:=1;
   filename:='';
   modf:=false;

   page_start();


end;

procedure TDrawingControl.make_load(Path:string);
  var FCF:Pcairo_surface_t;
     bb:Pcairo_t ;
    loop:integer;
    Devicebmp:TGtkDeviceContext;
begin
      Picture:= TPicture.Create;
      Picture.LoadFromFile(Path);



      for loop :=0 to (Length(Tundo)-1) do
      begin

        make_destroy(@Tundo[loop]);
        Tundo[loop].step:=-1;
      end;

      VUndo:=0;
      zoom:=1;
      filename:=Path;
      modf:=false;

      Devicebmp:=TGtkDeviceContext(Picture.Bitmap.Canvas.Handle);
      bb:=gdk_cairo_create(Devicebmp.Drawable);

      FCF:= cairo_get_target (bb);
      make_new(@Tundo[0],Picture.Width,Picture.Height);
      cairo_set_source_surface(Tundo[0].CR,FCF,0,0);
      cairo_paint(Tundo[0].CR);

      Picture.Free;
      cairo_surface_destroy(FCF);

      Bmpw := cairo_image_surface_get_width(Tundo[0].FC);
      Bmph := cairo_image_surface_get_height(Tundo[0].FC);
      Tundo[0].step:=0;
      page_start();

end;


procedure TDrawingControl.make_save(Path:string);
  var FCF:Pcairo_surface_t;
     bb:Pcairo_t ;
    loop:integer;
    Devicebmp:TGtkDeviceContext;
begin
      Picture:= TPicture.Create;
      Picture.Bitmap.Width:=Bmpw;
      Picture.Bitmap.Height:=Bmph;

      filename:=Path;
      modf:=false;
      Picture.Bitmap.Canvas.Line(0,0,0,0);
      Devicebmp:=TGtkDeviceContext(Picture.Bitmap.Canvas.Handle);
      bb:=gdk_cairo_create(Devicebmp.Drawable);

      cairo_set_source_surface(bb,Tundo[VUndo].FC,0,0);
      cairo_paint(bb);

      Picture.SaveToFile(Path);
      Picture.Free;
end;


procedure TDrawingControl.make_print(Path:string);
  var FCF:Pcairo_surface_t;
     bb:Pcairo_t ;
    loop:integer;
    Devicebmp:TGtkDeviceContext;
begin

      PrintVFo.printpic:=Tbitmap.Create;


      PrintVFo.printpic.Width:=Bmpw;
      PrintVFo.printpic.Height:=Bmph;

      PrintVFo.printpic.Canvas.Line(0,0,0,0);
      Devicebmp:=TGtkDeviceContext(PrintVFo.printpic.Canvas.Handle);
      bb:=gdk_cairo_create(Devicebmp.Drawable);

      cairo_set_source_surface(bb,Tundo[VUndo].FC,0,0);
      cairo_paint(bb);

        PrintVFo.ShowModal;
        PrintVFo.printpic.Free;
       {
      with Printer do
      try
          BeginDoc;
          Canvas.Font.Name := 'Courier New';
          Canvas.Font.Size := 10;
          Canvas.Font.Color := clBlack;
          Canvas.Draw(0,0,Picture.Bitmap);
          Canvas.TextOut(50, 50, 'test');
      finally
          EndDoc;
      end;

      Picture.Free;
      }
end;



procedure TDrawingControl.make_destroy(Lay:PLaye);
begin

   if Assigned(Lay^.CR) then cairo_destroy(Lay^.CR);
   if Assigned(Lay^.PL) then cairo_pattern_destroy(Lay^.PL);
   if Assigned(Lay^.FC) then cairo_surface_destroy(Lay^.FC);
   Lay^.CR:=nil; Lay^.PL:=nil;Lay^.FC:=nil;


end;
///undo
function  TDrawingControl.undo_get_next():byte;
begin
  if VUndo=(Length(Tundo)-1) then
  undo_get_next:=0
  else
  undo_get_next:= VUndo+1;
  modf:=True;

end;
function  TDrawingControl.undo_get_back():byte;
begin

  if VUndo=0 then
  undo_get_back:=(Length(Tundo)-1)
  else
  undo_get_back:= VUndo-1;
  modf:=True;

end;
procedure TDrawingControl.page_undo();
begin

if  (Tundo[undo_get_back].step <> -1) and (Tundo[undo_get_back].step< Tundo[VUndo].step) then

        VUndo:= undo_get_back ;
        rf:=1;
        SurfrSETDC();
        TmpStart();


end;
procedure TDrawingControl.page_redo();
begin

        if  (Tundo[undo_get_next].step <> -1) and (Tundo[undo_get_next].step> Tundo[VUndo].step) then
        VUndo:= undo_get_next ;
        SurfrSETDC();
        TmpStart();



end;
procedure TDrawingControl.page_unext();
begin


     make_destroy(@Tundo[undo_get_next]);
     make_new(@Tundo[undo_get_next],bmpw,bmph);
     cairo_set_source(Tundo[undo_get_next].CR,Tundo[VUndo].PL);
     cairo_paint(Tundo[undo_get_next].CR);
     Tundo[undo_get_next].step:=Tundo[VUndo].step+1;
     VUndo:=undo_get_next;
     Tundo[undo_get_next].step:=-1;

end;
procedure   TDrawingControl.Glob_Getsize();
begin



          PageRect[0].X :=(Bmpw-Scol_H^.Position)*zoom;
          PageRect[0].Y :=(Bmph-Scol_V^.Position)*zoom;


          PageRect[1].X :=(((Bmpw shr 1)-Scol_H^.Position)*zoom)+(zoom shr 1)-2;
          PageRect[1].Y :=(0-Scol_V^.Position)*zoom;

          PageRect[2].X :=(0-Scol_H^.Position)*zoom;;
          PageRect[2].Y :=(((Bmph shr 1)-Scol_V^.Position)*zoom)+(zoom shr 1)-2;


          PageRect[3].X  :=PageRect[0].X-5;
          PageRect[3].Y  :=(((Bmph shr 1)-Scol_V^.Position)*zoom)+(zoom shr 1)-2;


          PageRect[4].X  :=(((Bmpw shr 1)-Scol_H^.Position)*zoom)+(zoom shr 1)-2;
          PageRect[4].Y   :=PageRect[0].Y -5;


 end;

function TDrawingControl.BtoSXX(xv:integer):integer;
begin
    BtoSXX:=((xv-Scol_H^.Tag)*zoom)+(zoom div 2);
end;

function TDrawingControl.BtoSYY(Yv:integer):integer;
begin
    BtoSYY:=((yv-Scol_v^.Tag)*zoom)+(zoom div 2);
end;


procedure TDrawingControl.Paint;

begin
   RF:=1;
  IdleTimer1.Enabled:=true;

 // inherited Paint;
end;


procedure TDrawingControl.Clipboard_set();
var Devicebmp:TGtkDeviceContext;
    ClipbBitmap:Tbitmap;
    bb:Pcairo_t ;

begin
   ClipbBitmap :=TBitmap.Create;



   if Vmode.mode='MooB' then
   begin
       ClipbBitmap.SetSize(Vsel.Ssize.X,Vsel.Ssize.Y);
       ClipbBitmap.Canvas.Line(-1,-1,-1,-1);
       Devicebmp:=TGtkDeviceContext(ClipbBitmap.Canvas.Handle);
       bb:=gdk_cairo_create(Devicebmp.Drawable);
       cairo_set_source_surface(bb,ls0.FC,0,0);
   end else begin

       ClipbBitmap.SetSize(bmpw,bmph);
       ClipbBitmap.Canvas.Line(-1,-1,-1,-1);
       Devicebmp:=TGtkDeviceContext(ClipbBitmap.Canvas.Handle);
       bb:=gdk_cairo_create(Devicebmp.Drawable);
       cairo_set_source_surface(bb,Tundo[VUndo].FC,0,0);

   end;
    cairo_paint(bb);


   Clipboard.Assign(ClipbBitmap);
   cairo_destroy(bb);
   ClipbBitmap.Free;




end;

procedure TDrawingControl.Clipboard_get();
var Devicebmp:TGtkDeviceContext;
    ClipbBitmap:Tbitmap;
    ss:Pcairo_t ;
    FCF:Pcairo_surface_t;




begin

   ClipbBitmap :=TBitmap.Create;
   ClipbBitmap.Transparent:=true;
   if Clipboard.HasFormat(PredefinedClipboardFormat(pcfDelphiBitmap)) then
   ClipbBitmap.LoadFromClipboardFormat(PredefinedClipboardFormat(pcfDelphiBitmap));
   if Clipboard.HasFormat(PredefinedClipboardFormat(pcfBitmap)) then
   ClipbBitmap.LoadFromClipboardFormat(PredefinedClipboardFormat(pcfBitmap));



   if ClipbBitmap.Width <1 then Exit;
  Devicebmp:=TGtkDeviceContext(ClipbBitmap.Canvas.Handle);
   ss:=gdk_cairo_create(Devicebmp.Drawable);

  FCF:= cairo_get_target (ss);
  make_destroy(@ls0);
  make_new(@ls0,ClipbBitmap.Width,ClipbBitmap.Height);



  cairo_set_source_surface(ls0.CR,FCF,0,0);
  cairo_paint(ls0.CR);


  Vsel.Ssize.X:= cairo_image_surface_get_width(ls0.FC);
  Vsel.Ssize.Y:= cairo_image_surface_get_height(ls0.FC);
  Vsel.Spos.X:=Scol_H^.Tag;
  Vsel.Spos.Y:=Scol_V^.Tag;

  cairo_surface_destroy(FCF);

  ClipbBitmap.Free;




  make_destroy(@Lstmp);
  make_new(@Lstmp,Bmpw,Bmph);
  cairo_set_source_surface(Lstmp.CR,Tundo[VUndo].FC,0,0);
  cairo_paint(Lstmp.CR);
  MooB_Start();


end;

procedure Pcur();

var
   Cur: TCursorImage;

begin

 {
  Cur := TCursorImage.Create;
  Cur.LoadFromFile('cur/cu1-8.cur');
  Screen.Cursors[1] := Cur.ReleaseHandle;
  Screen.Cursors[8] := Cur.ReleaseHandle;
  Cur.Free;

  Cur := TCursorImage.Create;
  Cur.LoadFromFile('cur/cu2-7.cur');
  Screen.Cursors[2] := Cur.ReleaseHandle;
  Screen.Cursors[7] := Cur.ReleaseHandle;
  Cur.Free;

  Cur := TCursorImage.Create;
  Cur.LoadFromFile('cur/cu3-6.cur');
  Screen.Cursors[3] := Cur.ReleaseHandle;
  Screen.Cursors[6] := Cur.ReleaseHandle;
  Cur.Free;

  Cur := TCursorImage.Create;
  Cur.LoadFromFile('cur/cu4-5.cur');
  Screen.Cursors[4] := Cur.ReleaseHandle;
  Screen.Cursors[5] := Cur.ReleaseHandle;
  Cur.Free;



  Cur := TCursorImage.Create;
  Cur.LoadFromFile('cur/cu9.cur');
  Screen.Cursors[9] := Cur.ReleaseHandle;
  Cur.Free;

  Cur := TCursorImage.Create;
  Cur.LoadFromFile('cur/cu10.cur');
  Screen.Cursors[10] := Cur.ReleaseHandle;
  Cur.Free;

  Cur := TCursorImage.Create;
  Cur.LoadFromFile('cur/cu11.cur');
  Screen.Cursors[11] := Cur.ReleaseHandle;
  Cur.Free;
   Cur := TCursorImage.Create;
  Cur.LoadFromFile('cur/cu12.cur');
  Screen.Cursors[12] := Cur.ReleaseHandle;
  Cur.Free;

   Cur := TCursorImage.Create;
  Cur.LoadFromFile('cur/cu13.cur');
  Screen.Cursors[13] := Cur.ReleaseHandle;
  Cur.Free;

  Cur := TCursorImage.Create;
  Cur.LoadFromFile('cur/cu14.cur');
  Screen.Cursors[14] := Cur.ReleaseHandle;
  Cur.Free;

   Cur := TCursorImage.Create;
  Cur.LoadFromFile('cur/cu15.cur');
  Screen.Cursors[15] := Cur.ReleaseHandle;
  Cur.Free;



  Cur := TCursorImage.Create;
  Cur.LoadFromFile('cur/cu17.cur');
  Screen.Cursors[17] := Cur.ReleaseHandle;
  Cur.Free;

  Cur := TCursorImage.Create;
  Cur.LoadFromFile('cur/cu18.cur');
  Cur.LoadFromResourceName(nil,);
  Screen.Cursors[18] := Cur.ReleaseHandle;
  Cur.Free;
  }

    {$I cur.res}

 Screen.Cursors[1] := LoadCursorFromLazarusResource('cu1-8');
 Screen.Cursors[8] := LoadCursorFromLazarusResource('cu1-8');

  Screen.Cursors[2] := LoadCursorFromLazarusResource('cu2-7');
  Screen.Cursors[7] := LoadCursorFromLazarusResource('cu2-7');

  Screen.Cursors[3] := LoadCursorFromLazarusResource('cu3-6');
  Screen.Cursors[6] := LoadCursorFromLazarusResource('cu3-6');

  Screen.Cursors[4] := LoadCursorFromLazarusResource('cu4-5');
  Screen.Cursors[5] := LoadCursorFromLazarusResource('cu4-5');
  //
  Screen.Cursors[9 ] := LoadCursorFromLazarusResource('cu9');
  Screen.Cursors[10] := LoadCursorFromLazarusResource('cu10');
  Screen.Cursors[11] := LoadCursorFromLazarusResource('cu11');
  Screen.Cursors[12] := LoadCursorFromLazarusResource('cu12');
  Screen.Cursors[13] := LoadCursorFromLazarusResource('cu13');
  Screen.Cursors[14] := LoadCursorFromLazarusResource('cu14');
  Screen.Cursors[15] := LoadCursorFromLazarusResource('cu15');
  Screen.Cursors[17] := LoadCursorFromLazarusResource('cu17');
  Screen.Cursors[18] := LoadCursorFromLazarusResource('cu18');



end;



end.
