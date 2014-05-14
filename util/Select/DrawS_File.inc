procedure TDrawingControl.DrawS_start;
begin

    page_end();

   self.Cursor:=12;



    TmpStart:=@DrawS_start;


     SetLength(ArraySel,0);

     make_destroy(@ls0);
     make_destroy(@Lstmp);


     make_new(@ls0,Bmpw,Bmph);
     make_new(@Lstmp,Bmpw,Bmph);

     cairo_set_source(ls0.CR,Tundo[VUndo].PL);
     cairo_paint(ls0.CR);

     cairo_set_source(Lstmp.CR,Tundo[VUndo].PL);
     cairo_paint(Lstmp.CR);


     cairo_set_operator(Lstmp.CR,cairo_operator_t(24));
     cairo_set_source_rgb(Lstmp.CR,1,1,1);
     cairo_paint(Lstmp.CR);




     cairo_set_line_width (ls0.CR,1);
     cairo_set_source(ls0.CR,Lstmp.PL);


     IdleTimer1.OnTimer :=@DrawS_Render;
     OnMouseDown:=@DrawS_Mouse_Do;
     OnMouseMove:=@DrawS_Mouse_Mo;
     OnMouseUp  :=@DrawS_Mouse_Up;
     IdleTimer1.Enabled:=true;


end;






procedure TDrawingControl.DrawS_Render(Sender: TObject);


begin
   IdleTimer1.Enabled:=false;
   Glob_Getsize();
   if (bt.Width<>Width) or (bt.Height<>Height) then SurfrSETDC();

   cairo_scale(lsx.CR,zoom,zoom);
   cairo_translate(lsx.CR,-Scol_H^.Tag,-Scol_V^.Tag);
   cairo_set_source(lsx.CR,ls0.PL);
   cairo_translate(lsx.CR,Scol_H^.Tag,Scol_V^.Tag);
   cairo_scale(lsx.CR,1/zoom,1/zoom);
   cairo_paint(Lsx.CR);
   page_Backro();
   Self.Canvas.Draw(0,0,bt);




end;


procedure   TDrawingControl.DrawS_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
var drawsd: smallint;


const dclic:longword=0;

Var Hh,MMm,SS,MS : Word;


begin

               DeCodeTime (Time,Hh,MMm,SS,MS);





             {$i Ado.inc}

                     if ((MMm*60000)+(SS*1000)+MS) - dclic < 200 then
                     begin
                     OnMouseDown:=nil;
                     OnMouseMove:=nil;
                     OnMouseUp  :=nil;

                     DrawS_ok();
                     Exit;
                     end;
                     dclic:=((MMm*60000)+(SS*1000)+MS);


              cairo_set_line_width  (ls0.CR, 1);
              cairo_set_line_cap (ls0.CR, cairo_line_cap_t(2));
              cairo_set_fill_rule(ls0.CR,CAIRO_FILL_RULE_EVEN_ODD);





   if ML=1 then begin






                if IdleTimer1.Interval<>10 then IdleTimer1.Interval:=10;

                drawsd:= Length(ArraySel);

                if drawsd>0 then
                if (ArraySel[drawsd-1].X = VMov.BmovReal.X ) and (ArraySel[drawsd-1].y = VMov.BmovReal.Y ) then
                begin

                  Exit;
                 end;

                SetLength(ArraySel,drawsd+1);
                ArraySel[drawsd].X:=VMov.BmovReal.X;
                ArraySel[drawsd].Y:=VMov.BmovReal.Y;

                if drawsd = 0 then  begin
                cairo_set_line_cap  (ls0.CR, cairo_line_cap_t(1));
                cairo_move_to(ls0.CR,ArraySel[drawsd].X,ArraySel[drawsd].Y) ;
                cairo_line_to(ls0.CR,ArraySel[drawsd].X+0.5,ArraySel[drawsd].Y+0.5) ;
                cairo_stroke(ls0.CR);
                Sl_rect.Left:=VMov.BmovReal.X;
                Sl_rect.Right:=VMov.BmovReal.X;
                Sl_rect.Top:=VMov.BmovReal.Y;
                Sl_rect.Bottom:=VMov.BmovReal.Y;
                 IdleTimer1.Enabled:=true;
                exit;
                end  ;






                cairo_move_to(ls0.CR,ArraySel[drawsd-1].X+0.5,ArraySel[drawsd-1].Y+0.5) ;
                cairo_line_to(ls0.CR,ArraySel[drawsd].X+0.5,ArraySel[drawsd].Y+0.5) ;
                cairo_stroke  (ls0.CR);






                if VMov.BmovReal.X < Sl_rect.Left then Sl_rect.Left:=VMov.BmovReal.X;
                if VMov.BmovReal.X > Sl_rect.Right then Sl_rect.Right:=VMov.BmovReal.X;
                if VMov.BmovReal.y < Sl_rect.Top then Sl_rect.Top:=VMov.BmovReal.Y;
                if VMov.BmovReal.Y > Sl_rect.Bottom then Sl_rect.Bottom:=VMov.BmovReal.Y;

                if Sl_rect.Left<0 then Sl_rect.Left:=0;
                if Sl_rect.Top<0 then Sl_rect.Top:=0;
                if Sl_rect.Right  > Bmpw-1 then Sl_rect.Right  := Bmpw-1;
                if Sl_rect.Bottom  > Bmph-1 then Sl_rect.Bottom  := Bmph-1;





        IdleTimer1.Enabled:=true;

      end;











end;


procedure TDrawingControl.DrawS_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
var
drawsd: smallint;





begin

       {$i Amo.inc}






   if ML=1 then begin
               begin


               drawsd:= Length(ArraySel);

                if drawsd>0 then
                if (ArraySel[drawsd-1].X = VMov.BmovReal.X ) and (ArraySel[drawsd-1].y = VMov.BmovReal.Y ) then
                exit;


                SetLength(ArraySel,drawsd+1);
                ArraySel[drawsd].X:=VMov.BmovReal.X;
                ArraySel[drawsd].Y:=VMov.BmovReal.Y;

                if drawsd = 0 then  begin
                cairo_set_line_cap  (ls0.CR, cairo_line_cap_t(1));
                cairo_move_to(ls0.CR,ArraySel[drawsd].X,ArraySel[drawsd].Y) ;
                cairo_line_to(ls0.CR,ArraySel[drawsd].X+0.5,ArraySel[drawsd].Y+0.5) ;
                cairo_stroke(ls0.CR);
                Sl_rect.Left:=VMov.BmovReal.X;
                Sl_rect.Right:=VMov.BmovReal.X;
                Sl_rect.Top:=VMov.BmovReal.Y;
                Sl_rect.Bottom:=VMov.BmovReal.Y;
                exit;
                end  ;






                cairo_move_to(ls0.CR,ArraySel[drawsd-1].X+0.5,ArraySel[drawsd-1].Y+0.5) ;
                cairo_line_to(ls0.CR,ArraySel[drawsd].X+0.5,ArraySel[drawsd].Y+0.5) ;
                cairo_stroke(ls0.CR);

                if VMov.BmovReal.X < Sl_rect.Left then Sl_rect.Left:=VMov.BmovReal.X;
                if VMov.BmovReal.X > Sl_rect.Right then Sl_rect.Right:=VMov.BmovReal.X;
                if VMov.BmovReal.y < Sl_rect.Top then Sl_rect.Top:=VMov.BmovReal.Y;
                if VMov.BmovReal.Y > Sl_rect.Bottom then Sl_rect.Bottom:=VMov.BmovReal.Y;

                if Sl_rect.Left<0 then Sl_rect.Left:=0;
                if Sl_rect.Top<0 then Sl_rect.Top:=0;
                if Sl_rect.Right  > Bmpw-1 then Sl_rect.Right  := Bmpw-1;
                if Sl_rect.Bottom  > Bmph-1 then Sl_rect.Bottom  := Bmph-1;

                IdleTimer1.Enabled:=true;
               end;


    end;

end;




procedure   TDrawingControl.DrawS_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);

begin

        if MR=1 then begin
          DrawS_ok
         end;
        {$i Aup.inc}





end;

procedure   TDrawingControl.DrawS_ok();
   var drawsd: smallint;

begin









     if Length(ArraySel)>0 then

     begin


       make_destroy(@ls0);
       make_destroy(@Lstmp);




       Vsel.Ssize.X:= 1+Sl_rect.Right - Sl_rect.Left;
       Vsel.Ssize.Y:= 1+Sl_rect.Bottom - Sl_rect.Top;

       Vsel.Spos.X:=Sl_rect.Left;
       Vsel.Spos.Y:=Sl_rect.Top;


       make_new(@ls0,Vsel.Ssize.X,Vsel.Ssize.Y);
       cairo_set_line_width(ls0.CR,1);
       cairo_set_line_cap (ls0.CR, cairo_line_cap_t(2));
       cairo_set_fill_rule(ls0.CR,CAIRO_FILL_RULE_EVEN_ODD);




       cairo_set_source_surface(ls0.CR,Tundo[VUndo].FC,-Sl_rect.Left,-Sl_rect.Top);
       cairo_translate(ls0.CR,-Sl_rect.Left,-Sl_rect.Top);



        cairo_move_to(ls0.CR,ArraySel[0].X+0.5,ArraySel[0].Y+0.5) ;

        for drawsd := 0 to Length(ArraySel)-1 do
        begin


         cairo_line_to(ls0.CR,ArraySel[drawsd].X+0.5,ArraySel[drawsd].Y+0.5) ;

         cairo_stroke(ls0.CR);
         cairo_move_to(ls0.CR,ArraySel[drawsd].X+0.5,ArraySel[drawsd].Y+0.5) ;
        end;
         cairo_line_to(ls0.CR,ArraySel[0].X+0.5,ArraySel[0].Y+0.5) ;
         cairo_stroke(ls0.CR);

        for drawsd := 0 to Length(ArraySel)-1 do
        begin
        cairo_line_to(ls0.CR,ArraySel[drawsd].X+0.5,ArraySel[drawsd].Y+0.5) ;
        end;
        cairo_close_path(ls0.CR);
        cairo_fill(ls0.CR);






      clearsel_A(point(Vsel.Ssize.X,Vsel.Ssize.Y),cairo_image_surface_get_data(ls0.FC),true);






       make_new(@Lstmp,Bmpw,Bmph);
       cairo_set_line_width(Lstmp.CR,1);
       cairo_set_line_cap (Lstmp.CR, cairo_line_cap_t(2));
       cairo_set_fill_rule(Lstmp.CR,CAIRO_FILL_RULE_EVEN_ODD);
       cairo_set_source_surface(Lstmp.CR,Tundo[VUndo].FC,0,0);
       cairo_paint(Lstmp.CR);

       if  Vmode.cut then begin
         MooB_Start();
         SetLength(ArraySel,0);
         Exit;
       end;

        cairo_set_source_rgb(Lstmp.CR,
        Single(Vmode.colorB.Red)  /255,
        Single(Vmode.colorB.Green)/255,
        Single(Vmode.colorB.Blue) /255);

       cairo_move_to(Lstmp.CR,ArraySel[0].X+0.5,ArraySel[0].Y+0.5) ;

        for drawsd := 0 to Length(ArraySel)-1 do
        begin


         cairo_line_to(Lstmp.CR,ArraySel[drawsd].X+0.5,ArraySel[drawsd].Y+0.5) ;

         cairo_stroke(Lstmp.CR);
         cairo_move_to(Lstmp.CR,ArraySel[drawsd].X+0.5,ArraySel[drawsd].Y+0.5) ;
        end;
         cairo_line_to(Lstmp.CR,ArraySel[0].X+0.5,ArraySel[0].Y+0.5) ;
         cairo_stroke(Lstmp.CR);

        for drawsd := 0 to Length(ArraySel)-1 do
        begin
        cairo_line_to(Lstmp.CR,ArraySel[drawsd].X+0.5,ArraySel[drawsd].Y+0.5) ;
        end;
        cairo_close_path(Lstmp.CR);
        cairo_fill(Lstmp.CR);
        ////

         SetLength(ArraySel,0);
         MooB_Start();




  end;


end;













