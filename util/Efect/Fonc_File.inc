procedure TDrawingControl.Fonc_flV(m:Boolean);
 var tmp:Laye=(FC:nil;PL:nil;CR:nil;step:0);
     swap:Longint;
begin


    if (Vmode.mode='MooB') or (Vmode.mode='txt') then
     begin

       make_new(@tmp,Vsel.Ssize.Y,Vsel.Ssize.X);

        if m then
        begin
        cairo_translate(tmp.CR,Vsel.Ssize.Y,0);//-- >
        cairo_rotate(tmp.CR, pi/2);
          end else begin
        cairo_translate(tmp.CR,0,Vsel.Ssize.X);//<--
        cairo_rotate(tmp.CR, -pi/2);
        end;

       cairo_set_source(tmp.CR,Ls0.PL);
       cairo_paint(tmp.CR);

       make_destroy(@Ls0);
       make_new(@Ls0,Vsel.Ssize.Y,Vsel.Ssize.X);

       swap:=Vsel.Ssize.X;
       Vsel.Ssize.X:=Vsel.Ssize.Y;
       Vsel.Ssize.Y:=swap;

       cairo_set_source(Ls0.CR,tmp.PL);
       cairo_paint(Ls0.CR);

       make_destroy(@tmp);
       SurfrSETDC();
        exit;
     end;



    make_destroy(@Tundo[undo_get_next]);
    make_new(@Tundo[undo_get_next],bmph,bmpw);

    if m then
    begin
    cairo_translate(Tundo[undo_get_next].CR,bmph,0);//-- >
    cairo_rotate(Tundo[undo_get_next].CR, pi/2);
      end else begin
    cairo_translate(Tundo[undo_get_next].CR,0,bmpw);//<--
    cairo_rotate(Tundo[undo_get_next].CR, -pi/2);
    end;


     cairo_set_source(Tundo[undo_get_next].CR,Tundo[VUndo].PL);
     cairo_paint(Tundo[undo_get_next].CR);

     Tundo[undo_get_next].step:=Tundo[VUndo].step+1;
     VUndo:=undo_get_next;
     Tundo[undo_get_next].step:=-1;
     SurfrSETDC();
     if  drawZ.Vmode.mode='DrawS' then TmpStart;



end;

procedure TDrawingControl.Fonc_swap(m:Boolean);
 var tmp:Laye=(FC:nil;PL:nil;CR:nil;step:0);
     swap:Longint;
begin



    if (Vmode.mode='MooB') or (Vmode.mode='txt') then
     begin


       make_new(@tmp,Vsel.Ssize.x,Vsel.Ssize.y);

       cairo_set_source(tmp.CR,Ls0.PL);
       cairo_paint(tmp.CR);



      make_destroy(@Ls0);
      make_new(@Ls0,Vsel.Ssize.X,Vsel.Ssize.Y);

      if m then begin

      cairo_translate(Ls0.CR,0,Vsel.Ssize.Y);
      cairo_scale(Ls0.CR,1,-1);
      end else begin
      cairo_translate(Ls0.CR,Vsel.Ssize.X,0);
      cairo_scale(Ls0.CR,-1,1);
      end;

      cairo_set_source(Ls0.CR,tmp.PL);
      cairo_paint(Ls0.CR);



      make_destroy(@tmp);
      SurfrSETDC();
       exit;
     end;



    make_destroy(@Tundo[undo_get_next]);
    make_new(@Tundo[undo_get_next],bmpw,bmph);
    if m then begin

    cairo_translate(Tundo[undo_get_next].CR,0,bmph);
    cairo_scale(Tundo[undo_get_next].CR,1,-1);
    end else begin
    cairo_translate(Tundo[undo_get_next].CR,bmpw,0);
    cairo_scale(Tundo[undo_get_next].CR,-1,1);
    end;
     cairo_set_source(Tundo[undo_get_next].CR,Tundo[VUndo].PL);
    cairo_paint(Tundo[undo_get_next].CR);

     Tundo[undo_get_next].step:=Tundo[VUndo].step+1;
     VUndo:=undo_get_next;
     Tundo[undo_get_next].step:=-1;
     SurfrSETDC();

     if  drawZ.Vmode.mode='DrawS' then TmpStart;


end;
procedure TDrawingControl.Fonc_Shear(m:Double;b:Boolean);
  const
       bb:Boolean=false;
 var tmp:Laye;
     swap:Longint;
     matrix,matrix2:cairo_matrix_t;
     sw:Double;

begin

    sw:=Double(bmpw)/Double(bmph);

    bmpw:=bmpw+bmpw;
    make_destroy(@Tundo[undo_get_next]);
    make_new(@Tundo[undo_get_next],bmpw,bmph);




    cairo_matrix_init(@matrix,
      1.0, 0.0,
      sw, 1.0,
      0.0, 0.0);


    cairo_transform(Tundo[undo_get_next].CR, @matrix);
    cairo_set_source(Tundo[undo_get_next].CR,Tundo[VUndo].PL);
    cairo_paint(Tundo[undo_get_next].CR);







     Tundo[undo_get_next].step:=Tundo[VUndo].step+1;
     VUndo:=undo_get_next;
     Tundo[undo_get_next].step:=-1;
     SurfrSETDC();

    bb:=true;



end;
procedure TDrawingControl.test(blo:integer);
var families:PPPangoFontFamily;
    pixbuf:PGdkPixbuf ;
     error : PPGError =nil;
    clipboardg:PGtkClipboard;

begin
  writeln(modf);


end;
procedure getur(clipboard:PGtkClipboard; selection_data:PGtkSelectionData; data:gpointer);
begin
     writeln(selection_data^._type );
end;
procedure TDrawingControl.Fonc_color_inv();
 var tmp:Laye;
     swap:Longint;
begin


    if (Vmode.mode='MooB') or (Vmode.mode='txt') then
     begin



     cairo_set_operator(Ls0.CR,cairo_operator_t(24));
     cairo_set_source_rgb(Ls0.CR,1,1,1);
     cairo_paint(Ls0.CR);

     cairo_set_operator(Ls0.CR,cairo_operator_t(2));
     SurfrSETDC();
     exit;
     end;



    make_destroy(@Tundo[undo_get_next]);
    make_new(@Tundo[undo_get_next],bmpw,bmph);
    cairo_set_source(Tundo[undo_get_next].CR,Tundo[VUndo].PL);
    cairo_paint(Tundo[undo_get_next].CR);

    cairo_set_source_rgb(Tundo[undo_get_next].CR,1,1,1);
    cairo_set_operator(Tundo[undo_get_next].CR,cairo_operator_t(24));
    cairo_paint(Tundo[undo_get_next].CR);

    cairo_set_operator(Tundo[undo_get_next].CR,cairo_operator_t(2));

     Tundo[undo_get_next].step:=Tundo[VUndo].step+1;
     VUndo:=undo_get_next;
     Tundo[undo_get_next].step:=-1;
     SurfrSETDC();




end;
procedure TDrawingControl.Fonc_BW();
 var tmp:Laye;
     swap:Longint;
begin


    if (Vmode.mode='MooB') or (Vmode.mode='txt') then
     begin



     cairo_set_operator(Ls0.CR,cairo_operator_t(25));
     cairo_set_source_rgb(Ls0.CR,1,1,1);
     cairo_paint(Ls0.CR);

     cairo_set_operator(Ls0.CR,cairo_operator_t(2));
     SurfrSETDC();
     exit;
     end;



    make_destroy(@Tundo[undo_get_next]);
    make_new(@Tundo[undo_get_next],bmpw,bmph);
    cairo_set_source(Tundo[undo_get_next].CR,Tundo[VUndo].PL);
    cairo_paint(Tundo[undo_get_next].CR);

    cairo_set_source_rgb(Tundo[undo_get_next].CR,1,1,1);
    cairo_set_operator(Tundo[undo_get_next].CR,cairo_operator_t(25));
    cairo_paint(Tundo[undo_get_next].CR);

    cairo_set_operator(Tundo[undo_get_next].CR,cairo_operator_t(2));

     Tundo[undo_get_next].step:=Tundo[VUndo].step+1;
     VUndo:=undo_get_next;
     Tundo[undo_get_next].step:=-1;
     SurfrSETDC();




end;

