{
procedure   recdraw_start();
procedure   recdraw_end();
procedure   recdraw_Render(Sender: TObject);
procedure   recdraw_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer); 
procedure   recdraw_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
procedure   recdraw_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
procedure   recdraw_ok();

}




procedure   TDrawingControl.recdraw_start();

begin

      page_end();
      self.Cursor:=12;

      TmpStart:=@recdraw_start;


      OnMouseDown:=@recdraw_Mouse_Do;
      OnMouseup  :=@recdraw_Mouse_Up;
      OnMouseMove:=@recdraw_Mouse_Mo;
      IdleTimer1.OnTimer:=@recdraw_Render;


      SetLength(ArraySel,3);
      ArraySel[2].X:=0;

      if IdleTimer1.Interval<>20 then IdleTimer1.Interval:=20;
      IdleTimer1.Enabled:=true;






end;



procedure TDrawingControl.recdraw_Render(Sender: TObject);



begin
  IdleTimer1.Enabled:=false;
  Glob_Getsize();
  if (bt.Width<>Width) or (bt.Height<>Height) then SurfrSETDC();



   cairo_scale(lsx.CR,zoom,zoom);
   cairo_translate(lsx.CR,-Scol_H^.Tag,-Scol_V^.Tag);
   cairo_set_source(lsx.CR,Tundo[VUndo].PL);
   cairo_translate(lsx.CR,Scol_H^.Tag,Scol_V^.Tag);
   cairo_scale(lsx.CR,1/zoom,1/zoom);
   cairo_paint(Lsx.CR);
   page_Backro();


   if ML=0 then begin
     Self.Canvas.Draw(0,0,bt);
     exit;
   end;


   cairo_set_line_width(lsx.CR,Vmode.lineW*zoom);


   cairo_set_source_rgb(lsx.CR,
   Single(Vmode.colorA.Red)  /255,
   Single(Vmode.colorA.Green)/255,
   Single(Vmode.colorA.Blue) /255);

    if ArraySel[2].X=1 then
    begin
     cairo_rectangle(lsx.CR,
     BtoSXX(ArraySel[0].X)+0.5,
     BtoSyy(ArraySel[0].Y)+0.5,
     ((BtoSxx(ArraySel[1].x)-BtoSXX(ArraySel[0].X))),
     ((BtoSyy(ArraySel[1].y)-BtoSyy(ArraySel[0].Y))));


    end;
    if Vmode.line_full=0 then cairo_stroke(LsX.CR);
    if Vmode.line_full=2 then begin
        cairo_stroke_preserve(LsX.CR);
        cairo_fill(LsX.CR);
    end;

    if Vmode.line_full=1 then
    begin
      cairo_set_source_rgb(lsx.CR,
      Single(Vmode.colorB.Red)  /255,
      Single(Vmode.colorB.Green)/255,
      Single(Vmode.colorB.Blue) /255);

      cairo_fill_preserve(LsX.CR);

      cairo_set_source_rgb(lsx.CR,
      Single(Vmode.colorA.Red)  /255,
      Single(Vmode.colorA.Green)/255,
      Single(Vmode.colorA.Blue) /255);

      cairo_stroke(LsX.CR);
    end;
  page_Backro();
   Self.Canvas.Draw(0,0,bt);



end;


procedure   TDrawingControl.recdraw_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer); 
var drawsd: smallint;


begin

		        {$i Ado.inc}

		   if ml =1 then begin

		   if (ArraySel[2].X=0 )then
		   begin
		      ArraySel[0].X:=VMov.BmovReal.X;
		      ArraySel[0].Y:=VMov.BmovReal.Y;
		      ArraySel[1]:=ArraySel[0] ;
		
		      ArraySel[2].X:=1;
		      IdleTimer1.Enabled:=true;
		      Exit;
		   end;

                   end;

end;

procedure TDrawingControl.recdraw_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
  VAR drawsd:INTEGER;
  xxn,yyn:real;

begin



   {$i Amo.inc}

    if (ArraySel[2].X=1)then
    begin
      ArraySel[1].X:=VMov.BmovReal.X;
      ArraySel[1].Y:=VMov.BmovReal.Y;
      IdleTimer1.Enabled:=true;
    end;


end;





procedure   TDrawingControl.recdraw_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var drawsd: smallint;


begin
      if (mm=0)and (ArraySel[2].X=1) and(ArraySel[0].X <>ArraySel[1].X ) and (ArraySel[0].y <>ArraySel[1].y )then
       begin
       recdraw_ok();

       end;

     {$i Aup.inc}



       ArraySel[2].X:=0 ;
       rf:=1;
       IdleTimer1.Enabled:=true;





end;



procedure   TDrawingControl.recdraw_ok();

begin

   page_unext();

    cairo_set_antialias(Tundo[VUndo].CR,CAIRO_ANTIALIAS_NONE);


    cairo_set_line_width(Tundo[VUndo].CR,Vmode.lineW);


   cairo_set_source_rgb(Tundo[VUndo].CR,
   Single(Vmode.colorA.Red)  /255,
   Single(Vmode.colorA.Green)/255,
   Single(Vmode.colorA.Blue) /255);

   cairo_rectangle(Tundo[VUndo].CR,
   ArraySel[0].X+0.5,
   ArraySel[0].Y+0.5,
   (ArraySel[1].x-ArraySel[0].X)+0.5,
   (ArraySel[1].y-ArraySel[0].Y)+0.5);



   if Vmode.line_full=0 then cairo_stroke(Tundo[VUndo].CR);
    if Vmode.line_full=2 then begin
        cairo_stroke_preserve(Tundo[VUndo].CR);
        cairo_fill(Tundo[VUndo].CR);
    end;

    if Vmode.line_full=1 then
    begin
      cairo_set_source_rgb(Tundo[VUndo].CR,
      Single(Vmode.colorB.Red)  /255,
      Single(Vmode.colorB.Green)/255,
      Single(Vmode.colorB.Blue) /255);

      cairo_fill_preserve(Tundo[VUndo].CR);

      cairo_set_source_rgb(Tundo[VUndo].CR,
      Single(Vmode.colorA.Red)  /255,
      Single(Vmode.colorA.Green)/255,
      Single(Vmode.colorA.Blue) /255);

      cairo_stroke(Tundo[VUndo].CR);
    end;
end;










