{
procedure   circ_start();
procedure   circ_end();
procedure   circ_Render(Sender: TObject);
procedure   circ_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer); 
procedure   circ_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
procedure   circ_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
procedure   circ_ok();

}




procedure   TDrawingControl.circ_start();

begin


        self.Cursor:=12;
        page_end();
        TmpStart:=@circ_start;
        OnMouseDown:=@circ_Mouse_Do;
        OnMouseup:=@circ_Mouse_Up;
        OnMouseMove:=@circ_Mouse_Mo;
        IdleTimer1.OnTimer:=@circ_Render;


        SetLength(ArraySel,2);


       if IdleTimer1.Interval<>20 then IdleTimer1.Interval:=20;
       IdleTimer1.Enabled:=true;






end;





procedure TDrawingControl.circ_Render(Sender: TObject);

  procedure cir(x1,y1,x2,y2:Integer);
  var
    RT1,RT2,A1,A2,A3,A4: array [0..1] of real;
    x,y:byte;
    valx,valy:real;
  begin


    x:=0;y:=1;
   RT1[x]:=x1+0.5;
   RT1[y]:=y1+0.5;
   RT2[x]:=x2+0.5;
   RT2[y]:=y2+0.5;

   valx:=((RT2[x]-RT1[x])*0.28);
   valy:=((RT2[y]-RT1[y])*0.28);
   A1[x]:=(rt2[x]-rt1[x])/2+ rt1[x];
   A1[y]:=rt1[y];
   A2[x]:=rt1[x];
   A2[y]:=(rt2[y]-rt1[y])/2+ rt1[y];
   A3[x]:=rt2[x];
   A3[y]:=(rt2[y]-rt1[y])/2+ rt1[y];
   A4[x]:=(rt2[x]-rt1[x])/2+ rt1[x];
   A4[y]:=rt2[y];
   cairo_move_to  (lsx.CR, A1[x], A1[y]);
   cairo_curve_to (lsx.CR, A1[x]-valx,A1[y], A2[x],A2[y]-valy, A2[x], A2[y]);
   cairo_curve_to (lsx.CR, A2[x],A2[y]+valy, A4[x]-valx,A4[y], A4[x], A4[y]);
   cairo_curve_to (lsx.CR, A4[x]+valx,A4[y], A3[x],A3[y]+valy, A3[x], A3[y]);
   cairo_curve_to (lsx.CR, A3[x],A3[y]-valy, A1[x]+valx,A1[y], A1[x], A1[y]);


  end;

  function XX(xv:integer):integer;
  begin
      XX:=((xv-Scol_H^.Tag)*zoom)+(zoom div 2);
  end;

  function YY(Yv:integer):integer;
  begin
      YY:=((yv-Scol_v^.Tag)*zoom)+(zoom div 2);
  end;

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





   cairo_set_line_width(lsx.CR,Vmode.lineW*zoom);


   cairo_set_source_rgb(lsx.CR,
   Single(Vmode.colorA.Red)  /255,
   Single(Vmode.colorA.Green)/255,
   Single(Vmode.colorA.Blue) /255);

    if Length(ArraySel)>0 then
    begin
         cir(XX(ArraySel[0].X),yy(ArraySel[0].Y),xx(ArraySel[1].x),yy(ArraySel[1].y));


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


procedure   TDrawingControl.circ_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer); 
var drawsd: smallint;


begin


           {$i Ado.inc}

              if (ml =1) and (mm+mr=0) then
              begin

              ArraySel[0].X:=VMov.BmovReal.X;
              ArraySel[0].Y:=VMov.BmovReal.Y;
              ArraySel[1]:=ArraySel[0];
              end;

end;


procedure TDrawingControl.circ_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
  VAR drawsd:INTEGER;
  xxn,yyn:real;

begin


   {$i Amo.inc}


         if (ml =1) then
             begin

              ArraySel[1].X:=VMov.BmovReal.X;
              ArraySel[1].Y:=VMov.BmovReal.Y;
              IdleTimer1.Enabled:=true;
             end;


end;





procedure   TDrawingControl.circ_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var drawsd: smallint;


begin
     if  (mm=0)   then begin

     circ_ok();
     circ_start();
     ArraySel[0].X:=-100;
     ArraySel[0].Y:=-100;
     ArraySel[1]:=ArraySel[0];
     end;

     {$i Aup.inc}








end;



procedure   TDrawingControl.circ_ok();
var
    RT1,RT2,A1,A2,A3,A4: array [0..1] of real;
    x,y:byte;
    valx,valy:real;
begin

   page_unext();


   x:=0;y:=1;
   RT1[x]:=ArraySel[0].X+0.5;
   RT1[y]:=ArraySel[0].Y+0.5;
   RT2[x]:=ArraySel[1].X+0.5;
   RT2[y]:=ArraySel[1].Y+0.5;

   valx:=((RT2[x]-RT1[x])*0.28);
   valy:=((RT2[y]-RT1[y])*0.28);
   A1[x]:=(rt2[x]-rt1[x])/2+ rt1[x];
   A1[y]:=rt1[y];
   A2[x]:=rt1[x];
   A2[y]:=(rt2[y]-rt1[y])/2+ rt1[y];
   A3[x]:=rt2[x];
   A3[y]:=(rt2[y]-rt1[y])/2+ rt1[y];
   A4[x]:=(rt2[x]-rt1[x])/2+ rt1[x];
   A4[y]:=rt2[y];


    cairo_set_antialias(Tundo[VUndo].CR,CAIRO_ANTIALIAS_NONE);
    cairo_set_line_width(Tundo[VUndo].CR,Vmode.lineW);
    cairo_set_source_rgb(Tundo[VUndo].CR,
    Single(Vmode.colorA.Red)  /255,
    Single(Vmode.colorA.Green)/255,
    Single(Vmode.colorA.Blue) /255);






   cairo_move_to  (Tundo[VUndo].CR, A1[x], A1[y]);
   cairo_curve_to (Tundo[VUndo].CR, A1[x]-valx,A1[y], A2[x],A2[y]-valy, A2[x], A2[y]);
   cairo_curve_to (Tundo[VUndo].CR, A2[x],A2[y]+valy, A4[x]-valx,A4[y], A4[x], A4[y]);
   cairo_curve_to (Tundo[VUndo].CR, A4[x]+valx,A4[y], A3[x],A3[y]+valy, A3[x], A3[y]);
   cairo_curve_to (Tundo[VUndo].CR, A3[x],A3[y]-valy, A1[x]+valx,A1[y], A1[x], A1[y]);

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










