procedure   TDrawingControl.Fill_start();

begin
        page_end();

        if drawZ.Vmode.mode='pic' then self.Cursor:=14;
        if drawZ.Vmode.mode='fill' then self.Cursor:=17;
        Tmpstart    :=@Fill_start;
        OnMouseMove:=@Fill_Mouse_Mo;
        OnMouseDown:=@Fill_Mouse_Do;
        OnMouseUp  :=@Fill_Mouse_Up;
        IdleTimer1.OnTimer :=@Fill_Render;


        IdleTimer1.Enabled:=true;

end;



procedure TDrawingControl.Fill_Render(Sender: TObject);


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


procedure   TDrawingControl.Fill_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);

var
  rgbM: TFastRGBA;


begin
             {$i Ado.inc}




              if
              not((VMov.BmovReal.X<Bmpw)
              and(VMov.BmovReal.Y<Bmph)
              and(VMov.BmovReal.X>=0)
              and(VMov.BmovReal.Y>=0))
              then Exit;


             if Vmode.mode='fill' then
                    begin



                    if ML=1 then begin
                          rgbM.red:=Vmode.colorA.red;
                          rgbM.Green:=Vmode.colorA.Green;
                          rgbM.Blue:=Vmode.colorA.Blue;
                          rgbM.Alpha:=255;

                          page_unext();

                          cairo_surface_flush(Tundo[VUndo].FC);
                          FloodFillX(VMov.BmovReal.X,VMov.BmovReal.Y,point(Bmpw,Bmph),Longword(rgbM),pLongword(cairo_image_surface_get_data(Tundo[VUndo].FC)));
                          cairo_surface_mark_dirty (Tundo[VUndo].FC);
                    end;

                    if MR=1 then begin
                          rgbM.red:=Vmode.colorA.red;
                          rgbM.Green:=Vmode.colorA.Green;
                          rgbM.Blue:=Vmode.colorA.Blue;
                          rgbM.Alpha:=255;

                          page_unext();

                          cairo_surface_flush(Tundo[VUndo].FC);
                          Floodcolorall(point(VMov.BmovReal.X,VMov.BmovReal.Y),point(bmpw,bmph),Longword(rgbM),cairo_image_surface_get_data(Tundo[VUndo].FC));
                          cairo_surface_mark_dirty (Tundo[VUndo].FC);
                    end;

         end;


              if Vmode.mode='pic' then
                    begin



                    if ML=1 then begin
                     Unit1.Form1.ShcolorA.Brush.Color  :=integer(GetTcolor(point(VMov.BmovReal.X,VMov.BmovReal.Y),point(bmpw,bmph),cairo_image_surface_get_data(Tundo[VUndo].FC)));
                    end;

                    if MR=1 then begin
                      Unit1.Form1.ShcolorB.Brush.Color  :=integer(GetTcolor(point(VMov.BmovReal.X,VMov.BmovReal.Y),point(bmpw,bmph),cairo_image_surface_get_data(Tundo[VUndo].FC)));
                    end;

                    Unit1.Form1.update();

         end;



end;






procedure TDrawingControl.Fill_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);

begin
         {$i Amo.inc}
end;

procedure   TDrawingControl.Fill_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
{$i Aup.inc}
IdleTimer1.Enabled:=true;

end;











