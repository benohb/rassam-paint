{
procedure   Brr_start();
procedure   Brr_end();
procedure   Brr_Render(Sender: TObject);
procedure   Brr_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
procedure   Brr_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
procedure   Brr_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);

}
procedure   TDrawingControl.Brr_start();


begin
     page_end();
     self.Cursor:=18;
     TmpStart  :=@Brr_start;
     if IdleTimer1.Interval<>10 then IdleTimer1.Interval:=10;

     IdleTimer1.OnTimer :=@Brr_Render;
     OnMouseMove:=@Brr_Mouse_Mo;
     OnMouseDown:=@Brr_Mouse_Do;
     OnMouseUp  :=@Brr_Mouse_Up;
     IdleTimer1.Enabled:=true;
     SetLength(ArraySel,3);

end;

procedure TDrawingControl.Brr_Render(Sender: TObject);
 var drawsd,dox: smallint;

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
   Self.Canvas.Draw(0,0,bt);




end;


procedure   TDrawingControl.Brr_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var drawsd: smallint;




begin

           {$i Ado.inc}

              page_unext();


              cairo_set_antialias(Tundo[VUndo].CR,CAIRO_ANTIALIAS_NONE);
              cairo_set_line_cap(Tundo[VUndo].CR,cairo_line_cap_t(1)) ;

              cairo_set_source_rgb(Tundo[VUndo].CR,
              Single(Vmode.colorA.Red)  /255,
              Single(Vmode.colorA.Green)/255,
              Single(Vmode.colorA.Blue) /255);

              cairo_set_line_width(Tundo[VUndo].CR,Vmode.lineW);
              cairo_set_line_width(lsx.CR,(Vmode.lineW+2)*zoom);
              cairo_set_line_cap(lsx.CR,cairo_line_cap_t(1)) ;


   if ml=1 then begin

                if IdleTimer1.Interval<>20 then IdleTimer1.Interval:=20;


                 ArraySel[2].X:=1;


                ArraySel[0]:=VMov.BmovReal;
                ArraySel[1]:=VMov.BmovReal;

                cairo_move_to(Tundo[VUndo].CR,ArraySel[0].X+0.5,ArraySel[0].Y+0.5) ;
                cairo_line_to(Tundo[VUndo].CR,ArraySel[1].X+0.5,ArraySel[1].Y+0.5) ;
                cairo_stroke(Tundo[VUndo].CR);



                page_Backro();
                IdleTimer1.Enabled:=true;

      end;

end;


procedure TDrawingControl.Brr_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
 const pen:Double=8;
var
tmpintX,tmpintY,drawsd: smallint;


begin
      {$i Amo.inc}
       if ArraySel[2].X=1 then
       begin

        pen:=4*Vmode.lineW;
        ArraySel[2].X:=2
       end;

   if ml=1 then
               begin
              cairo_set_antialias(Tundo[VUndo].CR,CAIRO_ANTIALIAS_NONE);
              cairo_set_line_cap(Tundo[VUndo].CR,cairo_line_cap_t(1)) ;

              cairo_set_source_rgb(Tundo[VUndo].CR,
              Single(Vmode.colorA.Red)  /255,
              Single(Vmode.colorA.Green)/255,
              Single(Vmode.colorA.Blue) /255);



              cairo_set_line_cap(lsx.CR,cairo_line_cap_t(1)) ;



                ArraySel[1]:=VMov.BmovReal;

                cairo_move_to(Tundo[VUndo].CR,ArraySel[0].X+0.5,ArraySel[0].Y+0.5) ;
                cairo_line_to(Tundo[VUndo].CR,ArraySel[1].X+0.5,ArraySel[1].Y+0.5) ;
                cairo_stroke(Tundo[VUndo].CR);



                if max(abs(ArraySel[0].X-ArraySel[1].X),abs(ArraySel[0].y-ArraySel[1].y)) < 2 then
                pen:=pen+0.2
                else
                pen:=pen-Double(max(abs(ArraySel[0].X-ArraySel[1].X),abs(ArraySel[0].y-ArraySel[1].y)))/20;
                if pen<2 then pen:=2;
                if pen>4*Vmode.lineW then pen:=4*Vmode.lineW;


                cairo_set_line_width(Tundo[VUndo].CR,pen);
                cairo_set_antialias(Tundo[VUndo].CR,CAIRO_ANTIALIAS_DEFAULT);
                cairo_move_to(Tundo[VUndo].CR,ArraySel[0].X+0.5,ArraySel[0].Y+0.5) ;
                cairo_line_to(Tundo[VUndo].CR,ArraySel[1].X+0.5,ArraySel[1].Y+0.5) ;
                cairo_stroke(Tundo[VUndo].CR);
                cairo_set_antialias(Tundo[VUndo].CR,CAIRO_ANTIALIAS_NONE);

               end;
              ArraySel[0]:=VMov.BmovReal;
              ArraySel[1]:=VMov.BmovReal;
              IdleTimer1.Enabled:=true;

end;

procedure  TDrawingControl.Brr_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin

   {$i Aup.inc}
     IdleTimer1.Enabled:=true;


end;











