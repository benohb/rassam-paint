procedure TMyFrame.General_Render(Sender: TObject);


begin


    ST.Enabled:=false;

    reGet();
    hozX:=(GTObmpX-GetMdown_X)*zoom ;
    hozY:=(GTObmpy-GetMdown_Y)*zoom ;



       cairo_set_source(Xcr,lsR);
       cairo_rectangle(Xcr,0,0, PageRect[0].Right, PageRect[0].Bottom);
       cairo_fill(Xcr);





          cairo_set_antialias(Xcr,CAIRO_ANTIALIAS_NONE);
          cairo_set_line_width(Xcr,1);
          cairo_set_source_rgb(Xcr,0,0,1);


       //   cairo_rectangle(Xcr,PageRect[1].Left,PageRect[1].Top, PageRect[1].Right,PageRect[1].Bottom);
       //   cairo_rectangle(Xcr,PageRect[2].Left,PageRect[2].Top, PageRect[2].Right,PageRect[2].Bottom);
       //   cairo_rectangle(Xcr,PageRect[3].Left,PageRect[3].Top, PageRect[3].Right,PageRect[3].Bottom);

        //  cairo_fill(Xcr);

          cairo_set_source_rgb(Xcr,1,1,1);

          cairo_set_operator(Xcr,cairo_operator_t(24));

          if MG =1 then  begin




           cairo_set_line_width(Xcr,1);


         if curc=5 then begin
         cairo_rectangle(Xcr,0,0, PageRect[0].Right+hozx,PageRect[0].Bottom);
         end;



         if curc=7 then begin
         cairo_rectangle(Xcr,0,0, PageRect[0].Right,PageRect[0].Bottom+hozy);
         end;

         if curc=8 then begin

          cairo_rectangle(Xcr,0,0, PageRect[0].Right+hozx,PageRect[0].Bottom+hozy);
         end;

         if (curc < 200) and (curc >0) then cairo_stroke(Xcr);
         end;

          cairo_set_operator(Xcr,cairo_operator_t(2));



  end;




