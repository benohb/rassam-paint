{
procedure   dik_start();
procedure   dik_end();
procedure   dik_Render(Sender: TObject);
procedure   dik_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
procedure   dik_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
procedure   dik_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);

}
procedure   TDrawingControl.dik_start();


begin
     page_end();
     self.Cursor:=18;
     TmpStart  :=@dik_start;
     if IdleTimer1.Interval<>10 then IdleTimer1.Interval:=10;

     IdleTimer1.OnTimer :=@dik_Render;
     OnMouseMove:=@dik_Mouse_Mo;
     OnMouseDown:=@dik_Mouse_Do;
     OnMouseUp  :=@dik_Mouse_Up;
     IdleTimer1.Enabled:=true;
     SetLength(ArraySel,3);

end;

procedure TDrawingControl.dik_Render(Sender: TObject);
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


procedure   TDrawingControl.dik_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var drawsd: smallint;

 tmpintX,tmpintY: smallint;


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


                 ArraySel[1]:=VMov.BmovReal;

                tmpintX:= random(Vmode.lineW*10)-random(Vmode.lineW*10);
                tmpinty:= random(Vmode.lineW*10)-random(Vmode.lineW*10);

                if  Vmode.lineW=1 then
                 begin
                  cairo_rectangle(Tundo[VUndo].cr, ArraySel[1].X+tmpintX, ArraySel[1].Y+tmpintY,1, 1);

                 end else begin
                    cairo_arc(Tundo[VUndo].cr, ArraySel[1].X+tmpintX, ArraySel[1].Y+tmpintY,Double( Vmode.lineW) /1, 0, 2 * PI);

                  end;

                cairo_fill(Tundo[VUndo].CR);


                page_Backro();
                IdleTimer1.Enabled:=true;

      end;

end;


procedure TDrawingControl.dik_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);

var
tmpintX,tmpintY,drawsd: smallint;


begin
      {$i Amo.inc}


   if ml=1 then
               begin
              cairo_set_antialias(Tundo[VUndo].CR,CAIRO_ANTIALIAS_NONE);


              cairo_set_source_rgb(Tundo[VUndo].CR,
              Single(Vmode.colorA.Red)  /255,
              Single(Vmode.colorA.Green)/255,
              Single(Vmode.colorA.Blue) /255);



                ArraySel[1]:=VMov.BmovReal;

                tmpintX:= random(Vmode.lineW*10)-random(Vmode.lineW*10);
                tmpinty:= random(Vmode.lineW*10)-random(Vmode.lineW*10);

                if  Vmode.lineW=1 then
                 begin
                  cairo_rectangle(Tundo[VUndo].cr, ArraySel[1].X+tmpintX, ArraySel[1].Y+tmpintY,1, 1);

                 end else begin
                    cairo_arc(Tundo[VUndo].cr, ArraySel[1].X+tmpintX, ArraySel[1].Y+tmpintY,Double( Vmode.lineW) , 0, 2 * PI);

                  end;

                cairo_fill(Tundo[VUndo].CR);





               end;
              ArraySel[0]:=VMov.BmovReal;
              ArraySel[1]:=VMov.BmovReal;
              IdleTimer1.Enabled:=true;

end;

procedure  TDrawingControl.dik_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin

   {$i Aup.inc}
     IdleTimer1.Enabled:=true;


end;











