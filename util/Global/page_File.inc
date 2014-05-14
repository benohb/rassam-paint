procedure TDrawingControl.page_start();

begin
          Vmode.mode:='page';
          self.Cursor:=11;
          page_end();

          TmpStart:=@page_start;
          OnMouseDown:=@page_Mouse_Do;
          OnMouseup:=@page_Mouse_Up;
          OnMouseMove:=@page_Mouse_Mo;
          IdleTimer1.Enabled:=false;
          IdleTimer1.Interval:=20;
          IdleTimer1.OnTimer:=@page_Render;

          SurfrSETDC();
          rf:=1;
          IdleTimer1.Enabled:=true;

end;

procedure   TDrawingControl.page_end();

begin
 if (Vmode.mode='MooB') or (Vmode.mode='txt') then Vmode.mode:='';

 SetLength(ArraySel,0);
 make_destroy(@ls0);
 make_destroy(@Lstmp);


end;



procedure TDrawingControl.page_Render(Sender: TObject);

const aX :integer=0;
      aY :integer=0;
      bx :integer=0;
      bY :integer=0;

begin
   IdleTimer1.Enabled:=false;
   Glob_Getsize();
   if (bt.Width<>Width) or (bt.Height<>Height) then SurfrSETDC();












   if mm=1 then
   begin

   cairo_scale(lsx.CR,zoom,zoom);
   cairo_translate(lsx.CR,-Scol_H^.Tag,-Scol_V^.Tag);
   cairo_set_source(lsx.CR,Tundo[VUndo].PL);
   cairo_translate(lsx.CR,Scol_H^.Tag,Scol_V^.Tag);
   cairo_scale(lsx.CR,1/zoom,1/zoom);
   cairo_paint(Lsx.CR);
   page_Backro();
   Self.Canvas.Draw(0,0,bt);

   exit();
   end;

   if RF=1 then
   begin
   RF:=0;
   cairo_scale(lsx.CR,zoom,zoom);
   cairo_translate(lsx.CR,-Scol_H^.Tag,-Scol_V^.Tag);
   cairo_set_source(lsx.CR,Tundo[VUndo].PL);
   cairo_translate(lsx.CR,Scol_H^.Tag,Scol_V^.Tag);
   cairo_scale(lsx.CR,1/zoom,1/zoom);
   cairo_paint(Lsx.CR);
   page_Backro();
   Self.Canvas.Draw(0,0,bt);


    self.Canvas.Pen.Mode:=pmCopy;
    self.Canvas.Pen.Color:=clBlue;
    self.Canvas.Pen.Style:=psSolid;

   self.Canvas.Rectangle(PageRect[1].X,PageRect[1].y,PageRect[1].x+ 5,PageRect[1].y+5);
   self.Canvas.Rectangle(PageRect[2].x,PageRect[2].y,PageRect[2].x+ 5,PageRect[2].y+5);
   self.Canvas.Rectangle(PageRect[3].x,PageRect[3].y,PageRect[3].x+ 5,PageRect[3].y+5);
   self.Canvas.Rectangle(PageRect[4].x,PageRect[4].y, PageRect[4].x+5,PageRect[4].y+5);



   aX :=-1;
   aY :=-1;
   bx :=-1;
   bY :=-1;

   exit();
   end;

        self.Canvas.Pen.Mode:=pmxor;
        self.Canvas.Pen.Color:=clWhite ;
         self.Canvas.Pen.Style:=psDash;
        self.Canvas.Line(ax,ay,bx,by);





         if curc=2 then begin
         ax:=  0 ;
         ay:=  (VMov.BDiff.Y*zoom) ;
         bx:=  Self.Width ;
         by:=  (VMov.BDiff.Y*zoom) ;

         end;

         if curc=4 then begin
         ax:=  (VMov.BDiff.x*zoom) ;
         ay:=  0 ;
         bx:=  (VMov.BDiff.x*zoom) ;
         by:=  Self.Height ;
         end;

         if curc=5 then begin
         ax:= PageRect[0].X+ (VMov.BDiff.x*zoom) ;
         ay:=  0 ;
         bx:= PageRect[0].X+ (VMov.BDiff.x*zoom) ;
         by:=  Self.Height ;
         end;


         if curc=7 then begin
         ax:= 0;
         ay:=  PageRect[0].Y+ (VMov.BDiff.y*zoom) ; ;
         bx:= Self.Width ;
         by:=  PageRect[0].Y+(VMov.BDiff.y*zoom);
         end;


         self.Canvas.Line(ax,ay,bx,by);









  end;


procedure   TDrawingControl.page_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);


begin

        {$i Ado.inc}
         if ML=1 then begin
         curc:= Cursor;
         end;


end;

procedure TDrawingControl.page_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);

begin

       {$i Amo.inc}
      if ML=0  then begin
      page_Mouse_IN();
      end;
      IdleTimer1.Enabled:=true;


end;





procedure TDrawingControl.page_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);

begin
      {$i Aup.inc}




   if  ((VMov.BDiff.X<>0) or (VMov.BDiff.Y<>0)) AND (curc>=1) and (curc<=8) then begin

        page_resz();
        Glob_Getsize();


   end;


   curc:=11;
   page_Mouse_IN();

    rf:=1;
    IdleTimer1.Enabled:=true;
    Form1.upaMousepo();







end;





procedure TDrawingControl.page_Mouse_IN();


      function isit(yy:byte):Boolean;
      begin

       if   (VMov.XmovReal.X>=PageRect[yy].x) and (VMov.XmovReal.X<(PageRect[yy].x+7)) and
            (VMov.XmovReal.Y>=PageRect[yy].y)  and (VMov.XmovReal.Y<(PageRect[yy].y+7))  then
       begin
         exit (True)
       end;
         exit (false)
      end;

begin
      Glob_Getsize();


      if isit(4) then begin
      Cursor:=7;
      Exit;
      end;

      if isit(3) then begin
      Cursor:=5;
      Exit;
      end;

      if isit(2) then begin
      Cursor:=4;
      Exit;
      end;

      if isit(1) then begin

      Cursor:=2;
      Exit;
      end;


      Cursor:=11 ;





end;






procedure   TDrawingControl.page_resz();

var


    selW,selH:integer;



  begin

    if (curc=4) or (curc=5) then  VMov.BDiff.Y:=0;
    if (curc=2) or (curc=7) then  VMov.BDiff.X:=0;

    if (curc=5) or (curc=7) then begin
    selh:=Bmph+VMov.BDiff.Y;
    selW:=Bmpw+VMov.BDiff.X;
    end;

    if (curc=2) or (curc=4) then begin
    selh:=Bmph-VMov.BDiff.Y;
    selW:=Bmpw-VMov.BDiff.X;
    end;



     if selW<1 then  selW:=1;
     if selh<1 then  selh:=1;


     make_destroy(@Tundo[undo_get_next]);
     make_new(@Tundo[undo_get_next],selW,selH);

     cairo_set_source_rgb(Tundo[undo_get_next].CR,1,1,1);
     cairo_paint(Tundo[undo_get_next].CR);

     if (curc=2) or (curc=4) then begin
     cairo_set_source_surface(Tundo[undo_get_next].CR,Tundo[VUndo].FC,-VMov.BDiff.X,-VMov.BDiff.Y);
     end else begin
     cairo_set_source_surface(Tundo[undo_get_next].CR,Tundo[VUndo].FC,0,0);
     end;


     cairo_paint(Tundo[undo_get_next].CR);

     Tundo[undo_get_next].step:=Tundo[VUndo].step+1;
     VUndo:=undo_get_next;
     Tundo[undo_get_next].step:=-1;
     VMov.BDiff.Y:=0;
     VMov.BDiff.x:=0;

     SurfrSETDC();

  end;


procedure TDrawingControl.page_Backro();
begin
   // cairo_rectangle(LsX.CR, 0,0,Bmpw,Bmph);
  //  cairo_clip(Lsx.CR);

    cairo_set_source_rgb(LsX.CR,0.2,0.2,0.2);
    cairo_rectangle(LsX.CR, PageRect[0].X,0,Width,Height);
    cairo_rectangle(LsX.CR,0, PageRect[0].Y,Width,Height);
    cairo_fill(LsX.CR);



end;


