unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs,
  StdCtrls, ExtCtrls, ComCtrls, LCLClasses, LCLStrConsts

  ,LCLType,LCLIntf
  ,Menus, ExtDlgs

  ,GraphType, Buttons,zstream,Bitmapraw, LMessages
  ,Unit2,Unit3,Clipbrd,printV, IniPropStorage,abot;







type

  { TForm1 }

  TForm1 = class(TForm)
    Bevel1: TBevel;
    Bevel2: TBevel;

    Bevel3: TBevel;
    Button3: TButton;

    ColorDialog1: TColorDialog;
    cos_color1: TShape;
    cos_color10: TShape;
    cos_color11: TShape;
    cos_color12: TShape;
    cos_color13: TShape;
    cos_color14: TShape;
    cos_color15: TShape;
    cos_color16: TShape;
    cos_color17: TShape;
    cos_color18: TShape;
    cos_color19: TShape;
    cos_color2: TShape;
    cos_color20: TShape;
    cos_color21: TShape;
    cos_color22: TShape;
    cos_color23: TShape;
    cos_color24: TShape;
    cos_color25: TShape;
    cos_color26: TShape;
    cos_color27: TShape;
    cos_color28: TShape;
    cos_color29: TShape;
    cos_color3: TShape;
    cos_color30: TShape;
    cos_color31: TShape;
    cos_color32: TShape;
    cos_color33: TShape;
    cos_color34: TShape;
    cos_color35: TShape;
    cos_color36: TShape;
    cos_color37: TShape;
    cos_color38: TShape;
    cos_color39: TShape;
    cos_color4: TShape;
    cos_color40: TShape;
    cos_color41: TShape;
    cos_color42: TShape;
    cos_color43: TShape;
    cos_color44: TShape;
    cos_color45: TShape;
    cos_color46: TShape;
    cos_color47: TShape;
    cos_color48: TShape;
    cos_color49: TShape;
    cos_color5: TShape;
    cos_color50: TShape;
    cos_color51: TShape;
    cos_color52: TShape;
    cos_color53: TShape;
    cos_color54: TShape;
    cos_color55: TShape;
    cos_color56: TShape;
    cos_color57: TShape;
    cos_color58: TShape;
    cos_color59: TShape;
    cos_color6: TShape;
    cos_color60: TShape;
    cos_color61: TShape;
    cos_color62: TShape;
    cos_color63: TShape;
    cos_color7: TShape;
    cos_color8: TShape;
    cos_color9: TShape;
    IdleTimer1: TIdleTimer;
    IdleTimer2: TIdleTimer;
    ImageList1: TImageList;
    ImageList2: TImageList;
    IniPropStorage1: TIniPropStorage;
    OpenPictureDialog1: TOpenPictureDialog;
    Panel1: TPanel;


    Panel2: TPanel;
    Panel3: TPanel;
    Panel4: TPanel;
    Panelcolor: TPanel;
    Panelcolor1: TPanel;
    Panelcolor2: TPanel;
    Panelcolor3: TPanel;
    Panelcolor4: TPanel;
    Panelcolor5: TPanel;
    Panelcolor6: TPanel;
    Panel_zoom: TPanel;
    PanelDraw: TPanel;
    RecFulltype: TSpeedButton;
    SavePictureDialog1: TSavePictureDialog;
    ScrollBar1: TScrollBar;
    ScrollBar2: TScrollBar;
    ShcolorA: TShape;
    ShcolorB: TShape;
    SpeedButton1: TSpeedButton;
    SpeedButton10: TSpeedButton;
    SpeedButton11: TSpeedButton;
    SpeedButton12: TSpeedButton;
    SpeedButton2: TSpeedButton;
    SpeedButton4: TSpeedButton;
    SpeedButton6: TSpeedButton;
    SpeedButton9: TSpeedButton;
    ToolBar3: TToolBar;
    ToolButton22: TToolButton;
    ToolButton25: TToolButton;
    ToolButton26: TToolButton;
    ToolButton28: TToolButton;
    ToolButton30: TToolButton;
    zoompl: TSpeedButton;
    SpeedButton3: TSpeedButton;
    save: TSpeedButton;
    newp: TSpeedButton;
    SpeedButton7: TSpeedButton;
    SpeedButton8: TSpeedButton;
    zoommo: TSpeedButton;
    StatusBar1: TStatusBar;
    ToolBar1: TToolBar;
    ToolButton1: TToolButton;
    ToolButton10: TToolButton;
    ToolButton11: TToolButton;
    ToolButton12: TToolButton;
    ToolButton13: TToolButton;
    ToolButton14: TToolButton;
    ToolButton2: TToolButton;
    ToolButton3: TToolButton;
    ToolButton4: TToolButton;
    ToolButton5: TToolButton;
    ToolButton6: TToolButton;
    ToolButton7: TToolButton;
    ToolButton8: TToolButton;
    ToolButton9: TToolButton;
    zoompl1: TSpeedButton;
    zoompl2: TSpeedButton;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);

    procedure Button3Click(Sender: TObject);

    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure cos_color1MouseUp(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure FormCreate(Sender: TObject);
    procedure FormDragOver(Sender, Source: TObject; X, Y: Integer;
      State: TDragState; var Accept: Boolean);
    procedure FormDropFiles(Sender: TObject; const FileNames: array of String);
    procedure FormPaint(Sender: TObject);
    procedure FormShortCut(var Msg: TLMKey; var Handled: Boolean);
    procedure FormWindowStateChange(Sender: TObject);
    procedure grag1Click(Sender: TObject);
    procedure IdleTimer2Timer(Sender: TObject);
    procedure IniPropStorage1RestoreProperties(Sender: TObject);
    procedure MenuItem2Click(Sender: TObject);
    procedure newpClick(Sender: TObject);
    procedure IdleTimer1Timer(Sender: TObject);
    procedure Panel1Click(Sender: TObject);
    procedure Panel3Click(Sender: TObject);
    procedure Panelcolor1Click(Sender: TObject);
    procedure Panelcolor4Click(Sender: TObject);
    procedure Panel_zoomClick(Sender: TObject);
    procedure RecFulltypePaint(Sender: TObject);
    procedure ScrollBar1Scroll(Sender: TObject; ScrollCode: TScrollCode;
      var ScrollPos: Integer);
    procedure ShcolorADragOver(Sender, Source: TObject; X, Y: Integer;
      State: TDragState; var Accept: Boolean);
    procedure ShcolorAMouseUp(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure ShcolorBPaint(Sender: TObject);
    procedure SpeedButton10Click(Sender: TObject);
    procedure SpeedButton11Click(Sender: TObject);
    procedure SpeedButton15Click(Sender: TObject);
    procedure SpeedButton1Click(Sender: TObject);
    procedure SpeedButton8Click(Sender: TObject);
    procedure SpeedcutClick(Sender: TObject);
    procedure SpeedButton12Click(Sender: TObject);
    procedure SpeedButton13Click(Sender: TObject);
    procedure SpeedButton14Click(Sender: TObject);
    procedure RecFulltypeClick(Sender: TObject);
    procedure SpeedtxtClick(Sender: TObject);
    procedure SpeedButton3Click(Sender: TObject);
    procedure saveClick(Sender: TObject);
    procedure SpeedButton4Click(Sender: TObject);
    procedure SpeedButton5Click(Sender: TObject);
    procedure SpeedButton6Click(Sender: TObject);
    procedure SpeedButton9Click(Sender: TObject);

    procedure ToolButton4Click(Sender: TObject);
    procedure ToolButton9Click(Sender: TObject);
    procedure zoompl1Click(Sender: TObject);
    procedure zoompl2Click(Sender: TObject);


    procedure zoomresClick(Sender: TObject);
    procedure SpeedButton7Click(Sender: TObject);
    procedure ToolButton10Click(Sender: TObject);
    procedure ToolButton11Click(Sender: TObject);
    procedure ToolButton12Click(Sender: TObject);
    procedure ToolButton13Click(Sender: TObject);
    procedure ToolButton14Click(Sender: TObject);
    procedure ToolButton20Click(Sender: TObject);
    procedure ToolButton21Click(Sender: TObject);
    procedure ToolButton22Click(Sender: TObject);
    procedure ToolButton31Click(Sender: TObject);
    procedure ToolButton6Click(Sender: TObject);

    procedure ToolButton18Click(Sender: TObject);
    procedure ToolButton1Click(Sender: TObject);





    procedure ToolButton2Click(Sender: TObject);
    procedure ToolButton3Click(Sender: TObject);
    procedure ToolButton5Click(Sender: TObject);
    procedure ToolButton7Click(Sender: TObject);
    procedure ToolButton8Click(Sender: TObject);
    procedure updates();
    procedure upall();
    procedure upaMousepo();


  private
    { private declarations }
  public
    { public declarations }
  end;



var
  Form1: TForm1;
  zoomres:byte;
  actv:Boolean=false;

  bb:Tbitmap;
  drawZ:TDrawingControl;
  Papersize:Tpoint;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);

   var
  Buffer: array[0..1023] of Char;
  nRead: integer;
  CompressedFile: TFileStream;
  Compressor: TCompressionStream;
  DeCompressor: TDecompressionStream;
  ProcessingFile: TFileStream; // holding the uncompressed data
   var aa,bb:integer;
     cc:Pinteger;

begin


    {

  CompressedFile := TFileStream.Create('/tmp/33.png',fmOpenRead);
  ProcessingFile := TFileStream.Create('/tmp/44.png',fmCreate);
  DeCompressor := TDecompressionStream.Create(CompressedFile);
  repeat
    nRead := Decompressor.Read(Buffer,1024);
    ProcessingFile.Write(Buffer,nRead); // <===== decompressed data to target
  until nRead = 0;
  FreeAndNil(Decompressor);
  FreeAndNil(ProcessingFile);
  FreeAndNil(CompressedFile);


   }


end;



procedure TForm1.Button2Click(Sender: TObject);
  var
  Buffer: array[0..1023] of Char;
  nRead: integer;
  CompressedFile: TFileStream;
  Compressor: TCompressionStream;
  ProcessingFile: TMemoryStream; // holding the uncompressed data

  begin




          ProcessingFile := TMemoryStream.Create;
          ProcessingFile.LoadFromFile('/tmp/22.png');

          CompressedFile := TFileStream.Create('/tmp/33.png',fmCreate);

          Compressor := TCompressionStream.Create(clfastest,CompressedFile);
          repeat
            nRead := ProcessingFile.Read(Buffer,1024); // <===== source data to
            Compressor.Write(Buffer,nRead);
          until nRead = 0;
          writeln(ProcessingFile.Size);
          FreeAndNil(Compressor);
          FreeAndNil(CompressedFile);
          FreeAndNil(ProcessingFile);



 end;







procedure TForm1.Button3Click(Sender: TObject);


 var i : integer;
begin

  CreateDir(GetAppConfigDir(false));

  IniPropStorage1.IniFileName:=GetAppConfigDir(false)+'settings.ini';
   CopyFile('/usr/share/Rassam-paint/settings.ini',IniPropStorage1.IniFileName);
   IniPropStorage1.Active:=false;
   IniPropStorage1.Active:=true;
  IniPropStorage1.IniSection:='col0';

  for i :=1 to 40 do
     begin
      IniPropStorage1.WriteInteger(inttostr(i),TShape(Form1.FindComponent('cos_color'+inttostr(i))).Brush.Color)

     end;

  IniPropStorage1.Save;

end;



procedure TForm1.Button5Click(Sender: TObject);
begin

   drawZ.test(0);


end;

procedure TForm1.Button6Click(Sender: TObject);
begin
  drawZ.zoom:=1;
  drawZ.SurfrSETDC();
end;

procedure TForm1.cos_color1MouseUp(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
const dclic:longword=0;
  Var Hh,MMm,SS,MS : Word;
begin



    DeCodeTime (Time,Hh,MMm,SS,MS);
    if ((MMm*60000)+(SS*1000)+MS) - dclic < 200 then
    begin
    ColorDialog1.Execute;
    TShape(Sender).Brush.Color:=ColorDialog1.Color;
    end;
    dclic:=((MMm*60000)+(SS*1000)+MS);

    ShcolorA.Brush.Color :=TShape(Sender).Brush.Color;


end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  drawZ:=TDrawingControl.Create(self);
  drawZ.Parent := Panel3;
  drawZ.Align:=alClient;
  drawZ.BorderSpacing.Left:=2;
  drawZ.BorderSpacing.Top:=2;
  IdleTimer1.Enabled:=true;

  if FileExists(GetAppConfigDir(false)+'settings.ini') then
  IniPropStorage1.IniFileName:=GetAppConfigDir(false)+'settings.ini'
  else
  IniPropStorage1.IniFileName:='/usr/share/Rassam-paint/settings.ini'
  ;
  if FileExists('settings.ini') then
  IniPropStorage1.IniFileName:='settings.ini'
  ;

  IniPropStorage1.Active:=true;
end;

procedure TForm1.FormDragOver(Sender, Source: TObject; X, Y: Integer;
  State: TDragState; var Accept: Boolean);
begin
  Accept := true;
end;

procedure TForm1.FormDropFiles(Sender: TObject; const FileNames: array of String
  );
begin

  drawZ.make_load (FileNames[0]);
end;

procedure TForm1.FormPaint(Sender: TObject);
begin


end;

procedure TForm1.FormShortCut(var Msg: TLMKey; var Handled: Boolean);
begin


    if Msg.CharCode =86 then
    begin
     drawZ.Clipboard_get();
    end;
    if Msg.CharCode =67 then
    begin
     drawZ.Clipboard_set();
    end;

    if (drawZ.Vmode.mode='MooB') and(Msg.CharCode=46) then
   begin
   drawZ.MooB_del();
   end;

end;





procedure TForm1.FormWindowStateChange(Sender: TObject);
begin
  drawZ.SurfrSETDC();
end;

procedure TForm1.grag1Click(Sender: TObject);
begin

end;

procedure TForm1.IdleTimer2Timer(Sender: TObject);
  var  pageSiz:tpoint;
  begin
    if  (drawZ.Vmode.mode='page')
    then begin
     pageSiz.X:=drawZ.Bmpw;
     pageSiz.Y:=drawZ.Bmph;
     if drawZ.curc=2 then  pageSiz.Y :=drawZ.Bmph-drawZ.VMov.BDiff.Y;
     if drawZ.curc=7 then  pageSiz.Y :=drawZ.Bmph+drawZ.VMov.BDiff.Y;

     if drawZ.curc=4 then  pageSiz.x :=drawZ.Bmpw-drawZ.VMov.BDiff.x;
     if drawZ.curc=5 then  pageSiz.x :=drawZ.Bmpw+drawZ.VMov.BDiff.x;


    end else begin
      pageSiz.X:=drawZ.Bmpw;
      pageSiz.Y:=drawZ.Bmph;

    end;

     StatusBar1.Panels[1].Text:='W:'+inttostr(pageSiz.X);
     StatusBar1.Panels[2].Text:='H:'+inttostr(pageSiz.Y);
     StatusBar1.Panels[4].Text:='X:'+inttostr(drawZ.VMov.BmovReal.X+1);
     StatusBar1.Panels[5].Text:='Y:'+inttostr(drawZ.VMov.BmovReal.Y+1);



  IdleTimer2.Enabled:=false;
end;



procedure TForm1.IniPropStorage1RestoreProperties(Sender: TObject);
var i : integer;
begin
  for i :=1 to 40 do
     begin
       TShape(Form1.FindComponent('cos_color'+inttostr(i))).Brush.Color:=IniPropStorage1.ReadInteger(inttostr(i),0);;
     end;
    Papersize.X:=IniPropStorage1.ReadInteger('Papersize',0);
end;

procedure TForm1.MenuItem2Click(Sender: TObject);
begin

end;

procedure TForm1.newpClick(Sender: TObject);

 var rep:TModalResult;
begin


if drawZ.modf then
begin
    rep:=MessageDlg('Question', 'Do you want to save the image'+#13#10+drawZ.filename, mtConfirmation,
   [mbYes, mbNo, mbIgnore],0);


   if rep=5 then
   begin
     Exit;
   end;

   if rep=7 then
   begin
   drawZ.make_new_ph(500,500);
   upall();
   Exit;
   end;

   if rep=6 then
   begin
           if drawZ.filename ='' then
           begin
           SavePictureDialog1.Execute;
            if FileExists(SavePictureDialog1.FileName) then
            begin
              if MessageDlg('Question', 'Overwrite picture'+#13#10+SavePictureDialog1.filename, mtConfirmation,
              [mbYes, mbNo],0)=6then
              drawZ.filename:=SavePictureDialog1.FileName;
              end else begin
              drawZ.filename:=SavePictureDialog1.FileName;
            end;


           end;

           if drawZ.filename <>'' then
           begin
           drawZ.make_save(drawZ.filename);
           drawZ.make_new_ph(500,500);
           upall();
           end;


   Exit;
   end;
 end else begin

   drawZ.make_new_ph(500,500);
   upall();
   Exit;



end;

end;





procedure TForm1.IdleTimer1Timer(Sender: TObject);

begin

  IdleTimer1.Enabled:=false;
  drawZ.Scol_H:=@ScrollBar1;
  drawZ.Scol_V:=@ScrollBar2;

  drawZ.Vmode.colorA:=TRGBA(ShcolorA.Brush.Color);
  drawZ.Vmode.colorB:=TRGBA(ShcolorB.Brush.Color);

  drawZ.intt;

  if ParamStr(1)<>'' then
  drawZ.make_load (ParamStr(1))
  else
  drawZ.make_new_ph(500,500);

end;

procedure TForm1.Panel1Click(Sender: TObject);
begin

end;

procedure TForm1.Panel3Click(Sender: TObject);
begin

end;

procedure TForm1.Panelcolor1Click(Sender: TObject);
begin

end;

procedure TForm1.Panelcolor4Click(Sender: TObject);
begin

end;

procedure TForm1.Panel_zoomClick(Sender: TObject);
begin

end;

procedure TForm1.RecFulltypePaint(Sender: TObject);
begin
   RecFulltype.Canvas.Brush.Color:=TColor($277FFF);
  if RecFulltype.Tag = 0 then
  RecFulltype.Canvas.Frame(4,4,24,24);
    if RecFulltype.Tag = 1 then
  RecFulltype.Canvas.Rectangle(4,4,24,24);

  if RecFulltype.Tag = 2 then begin
  RecFulltype.Canvas.Brush.Color:=TColor($000000);
  RecFulltype.Canvas.Rectangle(4,4,24,24);



  end;


end;

procedure TForm1.ScrollBar1Scroll(Sender: TObject; ScrollCode: TScrollCode;
  var ScrollPos: Integer);
begin
  ScrollBar1.Tag:=ScrollBar1.Position;
  ScrollBar2.Tag:=ScrollBar2.Position;
  drawZ.RF:=1;
 drawZ.IdleTimer1.Enabled:=true;

end;

procedure TForm1.ShcolorADragOver(Sender, Source: TObject; X, Y: Integer;
  State: TDragState; var Accept: Boolean);
begin
      Accept := true;

end;

procedure TForm1.ShcolorAMouseUp(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
 ColorDialog1.Color:=TShape(Sender).Brush.Color;
  ColorDialog1.Execute;
  TShape(Sender).Brush.Color:=ColorDialog1.Color;

end;


procedure TForm1.ShcolorBPaint(Sender: TObject);
begin

  drawZ.Vmode.colorA:=TRGBA(ShcolorA.Brush.Color);
  drawZ.Vmode.colorB:=TRGBA(ShcolorB.Brush.Color);
   if drawZ.Vmode.mode='txt' then drawZ.txt_resz();


end;

procedure TForm1.SpeedButton10Click(Sender: TObject);
begin
  drawZ.Fonc_flV(false);
end;

procedure TForm1.SpeedButton11Click(Sender: TObject);
begin
  about.ShowModal;
end;

procedure TForm1.SpeedButton15Click(Sender: TObject);
begin

end;

procedure TForm1.SpeedButton1Click(Sender: TObject);
var ssw:TColor;
begin
 ssw:= ShcolorA.Brush.Color;
 ShcolorA.Brush.Color:=ShcolorB.Brush.Color ;
 ShcolorB.Brush.Color:=ssw;
end;



procedure TForm1.SpeedButton8Click(Sender: TObject);

begin
 // PrintDialog1.Execute;
  //if PrintDialog1.Execute then
  drawZ.make_print('');

end;

procedure TForm1.SpeedcutClick(Sender: TObject);
begin


end;

procedure TForm1.SpeedButton12Click(Sender: TObject);
begin
  drawZ.Fonc_swap(true);
end;

procedure TForm1.SpeedButton13Click(Sender: TObject);
begin
   drawZ.Fonc_color_inv();
end;

procedure TForm1.SpeedButton14Click(Sender: TObject);
begin
 // drawZ.Fonc_BW();

end;

procedure TForm1.RecFulltypeClick(Sender: TObject);
begin


 RecFulltype.Tag:=RecFulltype.Tag+1;
 if RecFulltype.Tag >2 then RecFulltype.Tag:=0;
 drawZ.Vmode.line_full:=RecFulltype.Tag;

end;

procedure TForm1.SpeedtxtClick(Sender: TObject);
begin
  Unit3.Form2.ShowModal;
end;

procedure TForm1.SpeedButton3Click(Sender: TObject);
 var rep:TModalResult;
begin
  OpenPictureDialog1.Execute;
 if OpenPictureDialog1.FileName = '' then Exit;

if drawZ.modf then
begin
    rep:=MessageDlg('Question', 'Do you want to save the image'+#13#10+drawZ.filename, mtConfirmation,
   [mbYes, mbNo, mbIgnore],0);


   if rep=5 then
   begin
     Exit;
   end;

   if rep=7 then
   begin
   drawZ.make_load(OpenPictureDialog1.FileName);
   upall();
   Exit;
   end;

   if rep=6 then
   begin
           if drawZ.filename ='' then
           begin
           SavePictureDialog1.Execute;
            if FileExists(SavePictureDialog1.FileName) then
            begin
              if MessageDlg('Question', 'Overwrite picture'+#13#10+SavePictureDialog1.filename, mtConfirmation,
              [mbYes, mbNo],0)=6then
              drawZ.filename:=SavePictureDialog1.FileName;
              end else begin
              drawZ.filename:=SavePictureDialog1.FileName;
            end;


           end;

           if drawZ.filename <>'' then
           begin
           drawZ.make_save(drawZ.filename);
           drawZ.make_load(OpenPictureDialog1.FileName);
           upall();
           end;


   Exit;
   end;
 end else begin

   drawZ.make_load(OpenPictureDialog1.FileName);
   upall();
   Exit;



end;

end;

procedure TForm1.saveClick(Sender: TObject);
begin



           if drawZ.filename ='' then
           begin
           SavePictureDialog1.Execute;
            if FileExists(SavePictureDialog1.FileName) then
            begin
              if MessageDlg('Question', 'Overwrite picture'+#13#10+SavePictureDialog1.filename, mtConfirmation,
              [mbYes, mbNo],0)=6then
              drawZ.filename:=SavePictureDialog1.FileName;
              end else begin
              drawZ.filename:=SavePictureDialog1.FileName;
            end;


           end;

           if drawZ.filename <>'' then
           begin
           drawZ.make_save(drawZ.filename);
           end;






 {
  var vv:TPicture;
 FC:Pcairo_surface_t;
 CR:Pcairo_t;

  vv:=TPicture.Create;
  vv.Bitmap.SetSize(drawZ.Bmpw,drawZ.Bmph);
  vv.Bitmap.Canvas.Line(-1,-1,-1,-1);
  FC:=CreateSurfaceFromDC(vv.Bitmap.Canvas.Handle,drawZ.Bmpw,drawZ.Bmph);
  CR:= cairo_create (FC);
  cairo_set_source_surface(CR,drawZ.Tundo[drawZ.VUndo].FC,0,0);
  cairo_paint(CR);
  //cairo_surface_create_similar





 // fc:=cairo_image_surface_create_from_png ('/tmp/Untitled3.png');
  //FC:=cairo_image_surface_create_f.or_data(vv.Bitmap.RawImage.Data,CAIRO_FORMAT_ARGB32,vv.Width,vv.Height,vv.Width*4);
   //vv.Bitmap.RawImage.Data:=pByte(cairo_image_surface_get_data(fc));



   vv.SaveToFile('/tmp/66.jpg','jpg');


 // cairo_surface_write_to_png(FC,'/tmp/1.png');
    cairo_destroy(CR);
    cairo_surface_destroy(FC);

  vv.Free;
   }
end;

procedure TForm1.SpeedButton4Click(Sender: TObject);
begin
  if SpeedButton4.Flat then
  begin
  drawZ.Vmode.fullback:=true;
   SpeedButton4.Flat:=false;
   SpeedButton4.Margin:=0;
  end else begin
     drawZ.Vmode.fullback:=false;
    SpeedButton4.Margin:=2;
   SpeedButton4.Flat:=true;
  end;

  if drawZ.Vmode.mode='MooB' then drawZ.MooB_clearback();
  if drawZ.Vmode.mode='txt' then drawZ.txt_clearback();
end;

procedure TForm1.SpeedButton5Click(Sender: TObject);
begin


end;

procedure TForm1.SpeedButton6Click(Sender: TObject);
begin
  drawZ.Fonc_swap(false);
end;

procedure TForm1.SpeedButton9Click(Sender: TObject);
begin
  drawZ.Fonc_flV(true);
end;



procedure TForm1.ToolButton4Click(Sender: TObject);
begin
  drawZ.mim_start();

end;

procedure TForm1.ToolButton9Click(Sender: TObject);
begin
  drawZ.dik_start();

end;

procedure TForm1.zoompl1Click(Sender: TObject);
begin
  drawZ.page_undo();
end;

procedure TForm1.zoompl2Click(Sender: TObject);
begin
  drawZ.page_redo();
end;



procedure TForm1.zoomresClick(Sender: TObject);
begin
if TSpeedButton(Sender).Tag=0 then drawZ.zoom:=1;

if TSpeedButton(Sender).Tag=1 then
 begin
 drawZ.zoom:=(drawZ.zoom shl 1);
 if  drawZ.zoom > 32 then drawZ.zoom:=32;
 end;

if TSpeedButton(Sender).Tag=2 then
 begin
 drawZ.zoom:=(drawZ.zoom shr 1);
 if  drawZ.zoom < 1 then drawZ.zoom:=1;
 end;



  drawZ.SurfrSETDC();
end;

procedure TForm1.SpeedButton7Click(Sender: TObject);
begin
           SavePictureDialog1.Execute;
            if FileExists(SavePictureDialog1.FileName) then
            begin
              if MessageDlg('Question', 'Overwrite picture'+#13#10+SavePictureDialog1.filename, mtConfirmation,
              [mbYes, mbNo],0)=6then
              drawZ.filename:=SavePictureDialog1.FileName;
              end else begin
              drawZ.filename:=SavePictureDialog1.FileName;
            end;

           if drawZ.filename <>'' then
           begin
           drawZ.make_save(drawZ.filename);
           end;
end;




procedure TForm1.ToolButton10Click(Sender: TObject);
begin
  drawZ.Vmode.mode:='Stxt';
  drawZ.selrect_start();

end;

procedure TForm1.ToolButton11Click(Sender: TObject);
begin
  drawZ.line_start();

end;

procedure TForm1.ToolButton12Click(Sender: TObject);
begin
     drawZ.arc_start();

end;

procedure TForm1.ToolButton13Click(Sender: TObject);
begin

  drawZ.Vmode.mode:='recdraw';
  drawZ.recdraw_start();
end;

procedure TForm1.ToolButton14Click(Sender: TObject);
begin

  drawZ.circ_start();
end;



procedure TForm1.ToolButton20Click(Sender: TObject);
begin
  drawZ.Fonc_flV(false);
end;

procedure TForm1.ToolButton21Click(Sender: TObject);
begin

end;

procedure TForm1.ToolButton22Click(Sender: TObject);
begin
  drawZ.Vmode.lineW:= TToolButton(Sender).ImageIndex+1;
end;

procedure TForm1.ToolButton31Click(Sender: TObject);
begin
  drawZ.Fonc_Shear(100.0,false);
end;

procedure TForm1.ToolButton6Click(Sender: TObject);
begin
   drawZ.Vmode.mode:='pic';
   drawZ.Fill_start();

end;



procedure TForm1.ToolButton18Click(Sender: TObject);
begin


end;

procedure TForm1.ToolButton1Click(Sender: TObject);
begin
  drawZ.page_start();
end;

procedure TForm1.ToolButton2Click(Sender: TObject);
begin
        drawZ.Vmode.mode:='DrawS';
        drawZ.DrawS_start();




end;

procedure TForm1.ToolButton3Click(Sender: TObject);
begin
  drawZ.Vmode.mode:='';
  drawZ.selrect_start();



end;

procedure TForm1.ToolButton5Click(Sender: TObject);
begin
  drawZ.Vmode.mode:='fill';
   drawZ.Fill_start();
end;

procedure TForm1.ToolButton7Click(Sender: TObject);
begin

  drawZ.Pen_start();
end;

procedure TForm1.ToolButton8Click(Sender: TObject);
begin
    drawZ.Vmode.mode:='brr';
  drawZ.brr_start();

end;

procedure TForm1.updates();
begin
  drawZ.Vmode.colorA:=TRGBA(ShcolorA.Brush.Color);
  drawZ.Vmode.colorB:=TRGBA(ShcolorB.Brush.Color);

end;
procedure TForm1.upall();

begin
 ToolButton1.Down:=true;

end;



procedure TForm1.upaMousepo();

begin




end;

end.

