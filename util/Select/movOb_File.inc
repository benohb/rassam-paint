procedure   TDrawingControl.MooB_Start();
 var
  rgbM: TFastRGBA;
begin
            Vmode.mode:='MooB';
            rgbM.Red:=Vmode.colorB.Blue;
            rgbM.Green:=Vmode.colorB.Green;
            rgbM.Blue:=Vmode.colorB.Red;
            rgbM.Alpha:=255;


            self.Canvas.Pen.Width:=1;
            if IdleTimer1.Interval<>20 then IdleTimer1.Interval:=20;



            OnMouseMove :=@MooB_Mouse_Mo;
            OnMouseDown :=@MooB_Mouse_Do;
            OnMouseUp   :=@MooB_Mouse_Up;
            IdleTimer1.OnTimer  :=@MooB_Render;

            cairo_surface_flush(ls0.FC);
            clearbackcolor(point(Vsel.Ssize.X,Vsel.Ssize.Y),Longword(rgbM),cairo_image_surface_get_data(ls0.FC), Vmode.fullback);
            cairo_surface_mark_dirty (ls0.FC);


            rf:=1;
            curc:= -1;
            IdleTimer1.Enabled:=true;
end;




procedure TDrawingControl.MooB_Render(Sender: TObject);

   const aX :integer=0;
         aY :integer=0;
         bx :integer=0;
         bY :integer=0;



begin

       IdleTimer1.Enabled:=false;
       if (bt.Width<>Width) or (bt.Height<>Height) then SurfrSETDC();


       if (mm=0) and (rf=0) and (ml=0)  then exit();

       Glob_Getsize();
       MooB_reGet();





           if MM=1 then
           begin


           cairo_scale(lsx.CR,zoom,zoom);
           cairo_translate(lsx.CR,-Scol_H^.Tag,-Scol_V^.Tag);
           cairo_set_source(lsx.CR,Lstmp.PL);
           cairo_translate(lsx.CR,Scol_H^.Tag,Scol_V^.Tag);
           cairo_scale(lsx.CR,1/zoom,1/zoom);
           cairo_paint(Lsx.CR);

           cairo_scale(lsx.CR,zoom,zoom);
           cairo_translate(lsx.CR,-Scol_H^.Tag,-Scol_V^.Tag);
           cairo_translate(lsx.CR,(Vsel.Spos.X),(Vsel.Spos.Y));
           cairo_set_source(lsx.CR,ls0.PL);
           cairo_translate(lsx.CR,-(Vsel.Spos.X),-(Vsel.Spos.Y));
           cairo_translate(lsx.CR,Scol_H^.Tag,Scol_V^.Tag);
           cairo_scale(lsx.CR,1/zoom,1/zoom);
           cairo_paint(Lsx.CR);
           page_Backro();
           Self.Canvas.Draw(0,0,bt);

           Exit;
           end;


          if RF=1 then
           begin
           RF:=0;

            if  Vmode.key=2  then begin
           cairo_translate(Lstmp.CR,Vsel.Spos.X+VMov.BDiff.X,Vsel.Spos.y+VMov.BDiff.y);
           cairo_set_source(Lstmp.CR,ls0.PL);
           cairo_translate(Lstmp.CR,-(Vsel.Spos.X+VMov.BDiff.X),-(Vsel.Spos.y+VMov.BDiff.y));
           cairo_paint(Lstmp.CR);
           end;

           cairo_scale(lsx.CR,zoom,zoom);
           cairo_translate(lsx.CR,-Scol_H^.Tag,-Scol_V^.Tag);
           cairo_set_source(lsx.CR,Lstmp.PL);
           cairo_translate(lsx.CR,Scol_H^.Tag,Scol_V^.Tag);
           cairo_scale(lsx.CR,1/zoom,1/zoom);
           cairo_paint(Lsx.CR);



           cairo_scale(lsx.CR,zoom,zoom);
           cairo_translate(lsx.CR,-Scol_H^.Tag,-Scol_V^.Tag);
           cairo_translate(lsx.CR,(Vsel.Spos.X),(Vsel.Spos.Y));
           cairo_set_source(lsx.CR,ls0.PL);
           cairo_translate(lsx.CR,-(Vsel.Spos.X),-(Vsel.Spos.Y));
           cairo_translate(lsx.CR,Scol_H^.Tag,Scol_V^.Tag);
           cairo_scale(lsx.CR,1/zoom,1/zoom);
           cairo_paint(Lsx.CR);


           page_Backro();
           Self.Canvas.Draw(0,0,bt);


            self.Canvas.Pen.Mode:=pmxor;
            self.Canvas.Pen.Color:=clWhite ;
            self.Canvas.Pen.Style:=psDash;
             self.Canvas.Frame(SelRect);

            self.Canvas.Pen.Mode:=pmCopy;
            self.Canvas.Pen.Color:=clBlue;
            self.Canvas.Pen.Style:=psSolid;

             self.Canvas.Rectangle(SelPon[1].X,SelPon[1].Y,SelPon[1].X+6,SelPon[1].y+6);
             self.Canvas.Rectangle(SelPon[2].X,SelPon[2].Y,SelPon[2].X+6,SelPon[2].y+6);
             self.Canvas.Rectangle(SelPon[3].X,SelPon[3].Y,SelPon[3].X+6,SelPon[3].y+6);
             self.Canvas.Rectangle(SelPon[4].X,SelPon[4].Y,SelPon[4].X+6,SelPon[4].y+6);
             self.Canvas.Rectangle(SelPon[5].X,SelPon[5].Y,SelPon[5].X+6,SelPon[5].y+6);
             self.Canvas.Rectangle(SelPon[6].X,SelPon[6].Y,SelPon[6].X+6,SelPon[6].y+6);
             self.Canvas.Rectangle(SelPon[7].X,SelPon[7].Y,SelPon[7].X+6,SelPon[7].y+6);
             self.Canvas.Rectangle(SelPon[8].X,SelPon[8].Y,SelPon[8].X+6,SelPon[8].y+6);

             aX :=-1;
             aY :=-1;
             bx :=-1;
             bY :=-1;

             Exit;
         end;

          if mm=2 then
          begin
            mm:=0;
          aX :=SelRect.Left;
          aY :=SelRect.Top;
          bx :=SelRect.Right;
          bY :=SelRect.Bottom;
          end;

           if curc=9 then
           begin

           if Vmode.key =1   then begin
           cairo_translate(Lstmp.CR,Vsel.Spos.X+VMov.BDiff.X,Vsel.Spos.y+VMov.BDiff.y);
           cairo_set_source(Lstmp.CR,ls0.PL);
           cairo_translate(Lstmp.CR,-(Vsel.Spos.X+VMov.BDiff.X),-(Vsel.Spos.y+VMov.BDiff.y));
           cairo_paint(Lstmp.CR);
           end;


           cairo_scale(lsx.CR,zoom,zoom);
           cairo_translate(lsx.CR,-Scol_H^.Tag,-Scol_V^.Tag);
           cairo_set_source(lsx.CR,Lstmp.PL);
           cairo_translate(lsx.CR,Scol_H^.Tag,Scol_V^.Tag);
           cairo_scale(lsx.CR,1/zoom,1/zoom);
           cairo_paint(Lsx.CR);

           cairo_scale(lsx.CR,zoom,zoom);
           cairo_translate(lsx.CR,-Scol_H^.Tag,-Scol_V^.Tag);
           cairo_translate(lsx.CR,(Vsel.Spos.X+VMov.BDiff.X),(Vsel.Spos.Y+VMov.BDiff.Y));
           cairo_set_source(lsx.CR,ls0.PL);
           cairo_translate(lsx.CR,-(Vsel.Spos.X+VMov.BDiff.X),-(Vsel.Spos.Y+VMov.BDiff.Y));
           cairo_translate(lsx.CR,Scol_H^.Tag,Scol_V^.Tag);
           cairo_scale(lsx.CR,1/zoom,1/zoom);
           cairo_paint(Lsx.CR);


           page_Backro();

           Self.Canvas.Draw(0,0,bt);

           Exit;
           end;



         self.Canvas.Pen.Mode:=pmxor;
         self.Canvas.Pen.Color:=clWhite ;
         self.Canvas.Pen.Style:=psDash;


           self.Canvas.Frame(ax,ay,bx,by);

           page_Backro();




         if curc=1 then begin
         aX :=SelRect.Left+(VMov.BDiff.X*zoom);
         aY :=SelRect.Top +(VMov.BDiff.Y*zoom);
         BX :=SelRect.Right;
         BY :=SelRect.Bottom;
         end;


         if curc=2 then begin
         aX :=SelRect.Left;
         aY :=SelRect.Top+(VMov.BDiff.Y*zoom);
         BX :=SelRect.Right;
         BY :=SelRect.Bottom;
         end;

         if curc=3 then begin
         aX :=SelRect.Left;
         aY :=SelRect.Top+(VMov.BDiff.Y*zoom); ;
         BX :=SelRect.Right+(VMov.BDiff.X*zoom);
         BY :=SelRect.Bottom;
         end;

         if curc=4 then begin
         aX :=SelRect.Left+(VMov.BDiff.X*zoom);
         aY :=SelRect.Top;
         BX :=SelRect.Right;
         BY :=SelRect.Bottom;
         end;

         if curc=5 then begin
         aX :=SelRect.Left;
         aY :=SelRect.Top;
         BX :=SelRect.Right+(VMov.BDiff.X*zoom);
         BY :=SelRect.Bottom;
         end;


         if curc=6 then begin
         aX :=SelRect.Left+(VMov.BDiff.X*zoom);
         aY :=SelRect.Top;
         BX :=SelRect.Right;
         BY :=SelRect.Bottom+(VMov.BDiff.Y*zoom);;
         end;

         if curc=7 then begin
         aX :=SelRect.Left;
         aY :=SelRect.Top;
         BX :=SelRect.Right;
         BY :=SelRect.Bottom+(VMov.BDiff.Y*zoom);;
         end;

         if curc=8 then begin
         aX :=SelRect.Left;
         aY :=SelRect.Top;
         BX :=SelRect.Right+(VMov.BDiff.X*zoom);;
         BY :=SelRect.Bottom+(VMov.BDiff.Y*zoom);
         end;

         if (curc<9) and (curc>0) then begin

         self.Canvas.Frame(ax,ay,bx,by);


         end;



  end;


procedure   TDrawingControl.MooB_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);




begin





   {$i Ado.inc}
   MM:=1;MooB_Render(nil);
   MM:=2;MooB_Render(nil);

   MooB_reGet();

   if ML=1 then begin
   curc:= Cursor;
   end;



end;

procedure TDrawingControl.MooB_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);

begin


   {$i Amo.inc}
       if  ssCtrl in Shift then
            Vmode.key:=1
            else
             Vmode.key:=0;

   if ML=0  then begin
      MooB_Mouse_IN();
   end;
   IdleTimer1.Enabled:=true;


end;





procedure  TDrawingControl.MooB_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);

begin

   if curc=9 then begin
    Vsel.Spos.X:=Vsel.Spos.X+VMov.BDiff.X  ;
    Vsel.Spos.Y:=Vsel.Spos.Y+VMov.BDiff.Y  ;

   end;

   if ((curc>=1) and (curc<=8)) and ((VMov.BDiff.X <> 0) or (VMov.BDiff.Y <>0)) then
     MooB_resz();

   if (curc=10) then
   begin
     MooB_ok();
     Exit;
   end;

   {$i Aup.inc}

     if  ssShift in Shift then
            Vmode.key:=2
            else
             Vmode.key:=0;

   MooB_reGet();
   MooB_Mouse_IN();
   curc:=crDefault;
   VMov.BDiff.X:=0;
   VMov.BDiff.y:=0;
   RF:=1;
   MooB_Render(nil);










end;


procedure TDrawingControl.MooB_Mouse_IN();


function isit(poin:byte):Boolean;
begin

 if   (VMov.XmovReal.X>=SelPon[poin].X) and (VMov.XmovReal.X<(SelPon[poin].X+6)) and
      (VMov.XmovReal.Y>=SelPon[poin].y) and (VMov.XmovReal.y<(SelPon[poin].Y+6))  then
  begin

   exit (True)
  end;
   exit (false)
end;

begin



if isit(8) then begin
 Cursor:=8;
 exit()
end;

if isit(7) then begin

 Cursor:=7;
 exit()
end;

if isit(6) then begin
 Cursor:=6;
 exit()
end;

if isit(5) then begin
 Cursor:=5;
 exit()
end;
if isit(4) then begin
 Cursor:=4;
 exit()
end;
if isit(3) then begin

 Cursor:=3;
 exit()
end;
if isit(2) then begin
 Cursor:=2;
 exit()
end;

if isit(1) then begin
 Cursor:=1;
 exit() ;
end;

if   (VMov.XmovReal.X>=SelRect.Left) and (VMov.XmovReal.X<SelRect.Right) and
     (VMov.XmovReal.Y>=SelRect.Top) and (VMov.XmovReal.y<SelRect.Bottom)  then
begin

   Cursor:=9;
   exit();
end;

  Cursor:=10;



end;


procedure   TDrawingControl.MooB_resz();


  var fceT:Laye=(FC:nil;PL:nil;CR:nil;step:0);

  scax,scay:Single;
  selW,selH:integer;
  flipV,flipH:byte;


begin



      selW:=Vsel.Ssize.X ;
      selH:=Vsel.Ssize.Y;
      flipV:=0;
      flipH:=0;



      if ((curc=1) or (curc=4) or (curc=6)) then begin
      Vsel.Spos.X:= Vsel.Spos.X+VMov.BDiff.X ;
      selW:= Vsel.Ssize.X-VMov.BDiff.X ;
      end;

      if ((curc=3) or (curc=5) or (curc=8))  then begin
      selW:=Vsel.Ssize.X+VMov.BDiff.X;
      end;


      if ((curc=1) or (curc=2) or (curc=3))  then begin
      Vsel.Spos.Y:= Vsel.Spos.Y+VMov.BDiff.Y  ;
      selH:= Vsel.Ssize.Y-VMov.BDiff.Y;
      end;


      if ((curc=6) or (curc=7) or (curc=8))  then begin
      selH:= Vsel.Ssize.Y+VMov.BDiff.Y;
      end;



      if selW<0 then begin
      selW:=abs(selW);
      Vsel.Spos.X:=Vsel.Spos.X - selW;
      flipV:=1;
      end;

      if selH<0 then begin
      selH:=abs(selH);
      Vsel.Spos.Y:=Vsel.Spos.Y - selH;
      flipH:=1;
      end;

      if selW=0 then begin
      selW :=1;
      end;

      if selH=0 then begin
      selH:=1;
      end;



      scax:=   Single(selW)/Single(Vsel.Ssize.X);
      scay:=   Single(selH)/Single(Vsel.Ssize.Y) ;

      make_new(@fceT,selW,selH);






      if flipV=1 then  begin
       cairo_translate(fceT.CR,selW,0);
        scax:=scax*-1;
      end;

      if flipH=1 then  begin
         cairo_translate(fceT.CR,0,selH);
         scay:=scay*-1;
      end;


     cairo_scale(fceT.CR,scax,scay);


     cairo_set_source(fceT.CR,Ls0.PL);
     cairo_paint(fceT.CR);


     make_destroy(@ls0);
     make_new(@ls0,selW,selH);

     cairo_set_source(ls0.CR,fceT.PL);
     cairo_paint(ls0.CR);

     Vsel.Ssize.X := selW;
     Vsel.Ssize.Y := selH;

     make_destroy(@fceT);

     RF:=1;
     IdleTimer1.Enabled:=true;

end;


procedure   TDrawingControl.MooB_reGet();
begin

          Glob_Getsize();
          SelRect.Left:=((Vsel.Spos.X-Scol_H^.Tag)*zoom)-1;
          SelRect.Right:=(SelRect.Left +(Vsel.Ssize.X*zoom))+2;
          SelRect.Top:=((Vsel.Spos.Y-Scol_V^.Tag)*zoom)-1;
          SelRect.Bottom:=(SelRect.Top+(Vsel.Ssize.Y*zoom))+2;

          SelPon[1].X:=SelRect.Left;
          SelPon[1].Y:=SelRect.Top;

          SelPon[2].X:=SelRect.Left+((SelRect.Right-SelRect.Left)shr 1)-3;
          SelPon[2].Y:=SelRect.Top;


          SelPon[3].X:=SelRect.Right-6;
          SelPon[3].Y:=SelRect.Top;


          SelPon[4].X:=SelRect.Left;
          SelPon[4].Y:=SelRect.Top+((SelRect.Bottom-SelRect.Top)shr 1)-3;

          SelPon[5].X:=SelRect.Right-6;
          SelPon[5].Y:=SelRect.Top+((SelRect.Bottom-SelRect.Top)shr 1)-3;

          SelPon[6].X:=SelRect.Left;
          SelPon[6].Y:=SelRect.Bottom-6;

          SelPon[7].X:=SelRect.Left+((SelRect.Right-SelRect.Left)shr 1)-3;
          SelPon[7].Y:=SelRect.Bottom-6;

          SelPon[8].X:=SelRect.Right-6;
          SelPon[8].Y:=SelRect.Bottom-6;


 end;




procedure   TDrawingControl.MooB_ok();


begin

  make_destroy(@Tundo[undo_get_next]);
  make_new(@Tundo[undo_get_next],bmpw,bmph);



  cairo_set_source(Tundo[undo_get_next].CR,Lstmp.PL);
  cairo_paint(Tundo[undo_get_next].CR);
  Tundo[undo_get_next].step:=Tundo[VUndo].step+1;
  VUndo:=undo_get_next;
  Tundo[undo_get_next].step:=-1;



  cairo_surface_flush(ls0.FC);
  clearsel_A(point(Vsel.Ssize.X,Vsel.Ssize.Y),cairo_image_surface_get_data(ls0.FC),false);
  cairo_surface_mark_dirty (ls0.FC);


  cairo_translate(Tundo[VUndo].CR,Vsel.Spos.X,Vsel.Spos.Y);
  cairo_set_source(Tundo[VUndo].CR,ls0.PL);
  cairo_paint(Tundo[VUndo].CR);


  page_end();

  TmpStart();


end;

procedure   TDrawingControl.MooB_clearback();


var
 rgbM: TFastRGBA;
begin

        rgbM.Red:=Vmode.colorB.Blue;
        rgbM.Green:=Vmode.colorB.Green;
        rgbM.Blue:=Vmode.colorB.Red;
        rgbM.Alpha:=255;

        cairo_surface_flush(ls0.FC);
        clearbackcolor(point(Vsel.Ssize.X,Vsel.Ssize.Y),Longword(rgbM),cairo_image_surface_get_data(ls0.FC),Vmode.fullback);
        cairo_surface_mark_dirty (ls0.FC);


        rf:=1;
        IdleTimer1.Enabled:=true;


end;

procedure   TDrawingControl.MooB_del();
begin
     make_destroy(@ls0);
     make_new(@ls0,Vsel.Ssize.X,Vsel.Ssize.Y) ;
     MooB_ok();



end;







