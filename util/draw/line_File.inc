
procedure   TDrawingControl.line_start();


begin
      page_end();
      self.Cursor:=12;
      if IdleTimer1.Interval<>10 then IdleTimer1.Interval:=10;


     TmpStart :=@line_start ;
     OnMouseMove :=@line_Mouse_Mo;
     OnMouseDown :=@line_Mouse_Do;
     OnMouseUp   :=@line_Mouse_Up;
     IdleTimer1.OnTimer  :=@line_Render;
     curc:=10;
     SetLength(ArraySel,3);
     ArraySel[2].X:=0;


end;



procedure TDrawingControl.line_Render(Sender: TObject);
  var
  rgbM: PTFastRGBA;
  XD,YD:Double;




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

   cairo_set_line_width(Lsx.CR,Vmode.lineW*zoom);

   if  (ArraySel[2].X<>0 )then
   begin



   cairo_set_source_rgb(Lsx.CR,
   Single(Vmode.colorA.Red)  /255,
   Single(Vmode.colorA.Green)/255,
   Single(Vmode.colorA.Blue) /255);


   cairo_set_line_cap (Lsx.CR, CAIRO_LINE_CAP_ROUND);

   cairo_move_to(Lsx.CR,BtoSXX(ArraySel[0].X)+0.5,BtoSYY(ArraySel[0].Y)+0.5);
   cairo_line_to(Lsx.CR,BtoSXX(ArraySel[1].X)+0.5,BtoSYY(ArraySel[1].Y)+0.5);
   cairo_stroke(Lsx.CR);


   end;

   page_Backro();
   Self.Canvas.Draw(0,0,bt);


end;


procedure   TDrawingControl.line_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);

begin

   {$i Ado.inc}



  if ml=0 then exit();

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


procedure TDrawingControl.line_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
begin

   {$i Amo.inc}
   if ml = 0 then exit;
    if (ArraySel[2].X=1)then
   begin
      ArraySel[1].X:=VMov.BmovReal.X;
      ArraySel[1].Y:=VMov.BmovReal.Y;

   end;



     IdleTimer1.Enabled:=true;
end;





procedure   TDrawingControl.line_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);


begin
    {$i Aup.inc}
     if  (Button=mbMiddle) then exit ;
     if (ArraySel[2].X=1)then
   begin
    ArraySel[2].X:=0;

    page_unext();
    cairo_set_line_width(Tundo[VUndo].CR,Vmode.lineW);
    cairo_set_line_cap (Tundo[VUndo].CR, CAIRO_LINE_CAP_ROUND);

    cairo_set_source_rgb(Tundo[VUndo].CR,
    Single(Vmode.colorA.Red)  /255,
    Single(Vmode.colorA.Green)/255,
    Single(Vmode.colorA.Blue) /255);

     cairo_move_to(Tundo[VUndo].CR,ArraySel[0].X+0.5,ArraySel[0].Y+0.5);
     cairo_line_to(Tundo[VUndo].CR,ArraySel[1].X+0.5,ArraySel[1].Y+0.5);

     cairo_stroke(Tundo[VUndo].CR);
     IdleTimer1.Enabled:=true;
      Exit;
   end;


end;











