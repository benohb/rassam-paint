{
procedure selrect_start();
procedure selrect_end();
procedure selrect_Render(Sender: TObject);
procedure selrect_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
procedure selrect_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);
procedure selrect_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
}




procedure TDrawingControl.selrect_start();

begin
     page_end();
     self.Cursor:=12;
     if IdleTimer1.Interval<>10 then IdleTimer1.Interval:=10;


     TmpStart :=@selrect_start ;
     OnMouseMove :=@selrect_Mouse_Mo;
     OnMouseDown :=@selrect_Mouse_Do;
     OnMouseUp   :=@selrect_Mouse_Up;
     IdleTimer1.OnTimer  :=@selrect_Render;
     curc:=10;
     SetLength(ArraySel,3);
     ArraySel[2].X:=0;
     rf:=1;
     IdleTimer1.Enabled:=true;

end;





procedure TDrawingControl.selrect_Render(Sender: TObject);

const aX :integer=0;
      aY :integer=0;
      bx :integer=0;
      bY :integer=0;

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



   aX :=-1;
   aY :=-1;
   bx :=-1;
   bY :=-1;

   exit();
   end;


      self.Canvas.Pen.JoinStyle:=pjsMiter;
      self.Canvas.Pen.Width:=1;
     if (ArraySel[2].X=1)then
    begin
     self.Canvas.Pen.Mode:=pmxor;
     self.Canvas.Pen.Color:=clWhite ;
     self.Canvas.Pen.Style:=psSolid;
     self.Canvas.Pen.Width:=zoom;

      self.Canvas.Rectangle(ax,ay,bx,by);
     aX :=xx(ArraySel[0].X);
     aY :=yy(ArraySel[0].Y);
     bx :=xx(ArraySel[1].X);
     bY :=yy(ArraySel[1].Y);
     self.Canvas.Rectangle(ax,ay,bx,by);

     end else begin
     aX :=-1;
     aY :=-1;
     bx :=-1;
     bY :=-1;

    end;







  end;


procedure   TDrawingControl.selrect_Mouse_Do(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);


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

procedure TDrawingControl.selrect_Mouse_Mo(Sender: TObject; Shift: TShiftState; X, Y: Integer);

begin

       {$i Amo.inc}

    if (ArraySel[2].X=1)then
    begin
      ArraySel[1].X:=VMov.BmovReal.X;
      ArraySel[1].Y:=VMov.BmovReal.Y;
      IdleTimer1.Enabled:=true;
    end;






end;





procedure TDrawingControl.selrect_Mouse_Up(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: Integer);

begin
      {$i Aup.inc}


       rf:=1;
       IdleTimer1.Enabled:=true;
       if ArraySel[2].X=1 then
       begin
       selrect_ok();

       end;


end;


procedure   TDrawingControl.selrect_ok();
   var drawsd: smallint;
begin





      if ArraySel[0].X<0 then ArraySel[0].X:=0 ;
      if ArraySel[1].X<0 then ArraySel[1].X:=0 ;
      if ArraySel[0].Y<0 then ArraySel[0].Y:=0;
      if ArraySel[1].Y<0 then ArraySel[1].Y:=0 ;

      if ArraySel[0].X>=Bmpw then ArraySel[0].X:=Bmpw-1;
      if ArraySel[1].X>=Bmpw then ArraySel[1].X:=Bmpw-1 ;
      if ArraySel[0].Y>=Bmph then ArraySel[0].Y:=Bmph-1 ;
      if ArraySel[1].Y>=Bmph then ArraySel[1].Y:=Bmph-1 ;


       Vsel.Ssize.X:= (max(ArraySel[0].X,ArraySel[1].X) - min(ArraySel[0].X,ArraySel[1].X))+1;
       Vsel.Ssize.Y:= (max(ArraySel[0].Y,ArraySel[1].Y) - min(ArraySel[0].Y,ArraySel[1].Y))+1;

      if Vsel.Ssize.X+Vsel.Ssize.Y=0 then exit();

       Vsel.Spos.X:=min(ArraySel[0].X,ArraySel[1].X);
       Vsel.Spos.Y:=min(ArraySel[0].Y,ArraySel[1].Y);


       ///
      make_new(@ls0,Vsel.Ssize.X,Vsel.Ssize.Y);
       if Vmode.mode='Stxt' then
       begin
        SetLength(ArraySel,0);
        txt_Start();
        exit();
       end;
      cairo_set_source_surface(ls0.CR,Tundo[VUndo].FC,-Vsel.Spos.X,-Vsel.Spos.Y);
      cairo_paint(ls0.CR);

       make_new(@Lstmp,Bmpw,Bmph);
       cairo_set_line_width(Lstmp.CR,1);
       cairo_set_line_cap (Lstmp.CR, cairo_line_cap_t(2));
       cairo_set_fill_rule(Lstmp.CR,CAIRO_FILL_RULE_EVEN_ODD);


       cairo_set_source_surface(Lstmp.CR,Tundo[VUndo].FC,0,0);
       cairo_paint(Lstmp.CR);

       if  Vmode.cut then begin
       MooB_Start();
       Exit;
       end;

       cairo_set_source_rgb(Lstmp.CR,
       Single(Vmode.colorB.Red)  /255,
       Single(Vmode.colorB.Green)/255,
       Single(Vmode.colorB.Blue) /255);


       cairo_rectangle(Lstmp.CR,Vsel.Spos.X,Vsel.Spos.Y,Vsel.Ssize.X,Vsel.Ssize.Y);
       cairo_fill(Lstmp.CR);
       SetLength(ArraySel,0);
        MooB_Start();







end;





