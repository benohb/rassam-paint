{
procedure   mim_start();
procedure   mim_Render(Sender: TObject);
procedure   mim_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
procedure   mim_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
procedure   mim_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);

}
procedure   TDrawingControl.mim_start();


begin
     page_end();
     self.Cursor:=18;
     TmpStart  :=@mim_start;
     if IdleTimer1.Interval<>10 then IdleTimer1.Interval:=10;

     IdleTimer1.OnTimer :=@mim_Render;
     OnMouseMove:=@mim_Mouse_Mo;
     OnMouseDown:=@mim_Mouse_Do;
     OnMouseUp  :=@mim_Mouse_Up;
     IdleTimer1.Enabled:=true;
     SetLength(ArraySel,3);

end;

procedure TDrawingControl.mim_Render(Sender: TObject);
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


procedure   TDrawingControl.mim_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var drawsd: smallint;




begin

           {$i Ado.inc}

              page_unext();


              cairo_set_antialias(Tundo[VUndo].CR,CAIRO_ANTIALIAS_NONE);
              cairo_set_line_cap(Tundo[VUndo].CR,cairo_line_cap_t(1)) ;

              cairo_set_source_rgb(Tundo[VUndo].CR,
              Single(Vmode.colorb.Red)  /255,
              Single(Vmode.colorb.Green)/255,
              Single(Vmode.colorb.Blue) /255);

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


procedure TDrawingControl.mim_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);

begin
      {$i Amo.inc}


   if ml=1 then
               begin
              cairo_set_antialias(Tundo[VUndo].CR,CAIRO_ANTIALIAS_NONE);
              cairo_set_line_cap(Tundo[VUndo].CR,cairo_line_cap_t(1)) ;
              cairo_set_line_cap(lsx.CR,cairo_line_cap_t(1)) ;

              ArraySel[1]:=VMov.BmovReal;

                cairo_move_to(Tundo[VUndo].CR,ArraySel[0].X+0.5,ArraySel[0].Y+0.5) ;
                cairo_line_to(Tundo[VUndo].CR,ArraySel[1].X+0.5,ArraySel[1].Y+0.5) ;
                cairo_stroke(Tundo[VUndo].CR);




               end;
              ArraySel[0]:=VMov.BmovReal;
              ArraySel[1]:=VMov.BmovReal;
              IdleTimer1.Enabled:=true;

end;

procedure  TDrawingControl.mim_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin

   {$i Aup.inc}
     IdleTimer1.Enabled:=true;


end;











