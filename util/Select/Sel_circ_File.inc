
procedure TMyFrame.circ_Render(Sender: TObject);

  procedure cir(x1,y1,x2,y2:Integer);
  var
    RT1,RT2,A1,A2,A3,A4: array [0..1] of real;
    x,y:byte;
    valx,valy:real;
  begin


    x:=0;y:=1;
   RT1[x]:=x1+0.5;
   RT1[y]:=y1+0.5;
   RT2[x]:=x2+0.5;
   RT2[y]:=y2+0.5;

   valx:=((RT2[x]-RT1[x])*0.28);
   valy:=((RT2[y]-RT1[y])*0.28);
   A1[x]:=(rt2[x]-rt1[x])/2+ rt1[x];
   A1[y]:=rt1[y];
   A2[x]:=rt1[x];
   A2[y]:=(rt2[y]-rt1[y])/2+ rt1[y];
   A3[x]:=rt2[x];
   A3[y]:=(rt2[y]-rt1[y])/2+ rt1[y];
   A4[x]:=(rt2[x]-rt1[x])/2+ rt1[x];
   A4[y]:=rt2[y];
   cairo_move_to  (lsx.CR, A1[x], A1[y]);
   cairo_curve_to (lsx.CR, A1[x]-valx,A1[y], A2[x],A2[y]-valy, A2[x], A2[y]);
   cairo_curve_to (lsx.CR, A2[x],A2[y]+valy, A4[x]-valx,A4[y], A4[x], A4[y]);
   cairo_curve_to (lsx.CR, A4[x]+valx,A4[y], A3[x],A3[y]+valy, A3[x], A3[y]);
   cairo_curve_to (lsx.CR, A3[x],A3[y]-valy, A1[x]+valx,A1[y], A1[x], A1[y]);


  end;


begin
  Glob_Getsize();

  ST.Enabled:=false;


   cairo_scale(lsx.CR,zoom,zoom);
   cairo_translate(lsx.CR,-xscoll.Position,-yscoll.Position);
   cairo_set_source(lsx.CR,Tundo[VUndo].PL);
   cairo_paint(Lsx.CR);
   cairo_translate(lsx.CR,xscoll.Position,yscoll.Position);
   cairo_scale(lsx.CR,1/zoom,1/zoom);






    cairo_set_source_rgb(lsx.CR,1,1,1);
    cairo_set_line_width(lsx.CR,zoom);
    cairo_set_antialias(lsx.CR,CAIRO_ANTIALIAS_NONE);


    if Length(ArraySel)>0 then
    begin
         cir(ArraySel[0].X,ArraySel[0].Y,ArraySel[1].x,ArraySel[1].y);
         ArraySel[1].X:=ArraySel[0].X;
         ArraySel[1].Y:=ArraySel[0].y;

    end;
    cairo_stroke(LsX.CR);

  page_Backro();



end;


procedure   TMyFrame.circ_Mouse_Do(Sender: TObject; AButton: TMouseButton; AShift: TShiftState; const AMousePos: TPoint);
var drawsd: smallint;


begin



             if AButton=mbRight then MD:=1;
             if AButton=mbMiddle then MM:=1;
             if AButton=mbLeft then MG:=1;

             VMov.XmovReal:=AMousePos;
             VMov.BmovReal.X:=( VMov.XmovReal.X  div zoom)+Xscoll.Position ;
             VMov.BmovReal.y:=( VMov.XmovReal.Y  div zoom)+Yscoll.Position ;
             VMov.XFixDown:=AMousePos;
             VMov.BFixDown:=VMov.BmovReal;
             VMov.scoll.X:=Xscoll.Position;
             VMov.scoll.Y:=Yscoll.Position;

             if AButton=mbMiddle then begin
             SetLength(ArraySel,0);
             st.Enabled:=true;
             exit();

             end;


              SetLength(ArraySel,2);
              ArraySel[0].X:=((VMov.XmovReal.X div zoom)*zoom)+(zoom div 2);
              ArraySel[0].Y:=((VMov.XmovReal.Y div zoom)*zoom)+(zoom div 2); ;
              ArraySel[1]:=ArraySel[0];





























end;


procedure TMyFrame.circ_Mouse_Mo(Sender: TObject; AShift: TShiftState; const AMousePos: TPoint);
  VAR drawsd:INTEGER;
  xxn,yyn:real;

begin










    if ssRight  in AShift then MD:=1 else MD:=0;
    if ssMiddle in AShift then MM:=1 else MM:=0;
    if ssLeft   in AShift then MG:=1 else MG:=0;




        VMov.XmovReal:=AMousePos;
        VMov.BmovReal.X:=( VMov.XmovReal.X  div zoom)+VMov.scoll.X ;
        VMov.BmovReal.y:=( VMov.XmovReal.Y  div zoom)+VMov.scoll.Y ;


        if  ssMiddle in AShift then begin
        Xscoll.Position:= VMov.scoll.X-(VMov.bmovReal.X-VMov.bFixDown.X);
        Yscoll.Position:= VMov.scoll.Y-(VMov.bmovReal.Y-VMov.bFixDown.Y);
        ST.Enabled:=true;
        exit();
        end;


         if Length(ArraySel)>0 then
             begin

              ArraySel[1].X:=((VMov.XmovReal.X div zoom)*zoom)+(zoom div 2);
              ArraySel[1].Y:=((VMov.XmovReal.Y div zoom)*zoom)+(zoom div 2);
              ST.Enabled:=true;
             end;


end;





procedure   TMyFrame.circ_Mouse_Up(Sender: TObject; AButton: TMouseButton; AShift: TShiftState; const AMousePos: TPoint);
var drawsd: smallint;


begin

     if AButton=mbRight  then MD:=0;
     if AButton=mbMiddle then MM:=0;
     if AButton=mbLeft   then MG:=0;



    if (VMov.BFixDown.X<>VMov.BmovReal.X) and (VMov.BFixDown.y<>VMov.BmovReal.y) and (AButton=mbLeft) then


     circ_ok();
     circ_start();



end;

procedure   TMyFrame.circ_start();


begin


   if TmpEnd<>nil then TmpEnd;
   TmpEnd:=@circ_end;
   TmpStart:=@circ_start;

     SetLength(ArraySel,0);
     OnMouseDown:=@circ_Mouse_Do;
     OnMouseup:=@circ_Mouse_Up;
     OnMouseMove:=@circ_Mouse_Mo;
     ST.OnTimer:=@circ_Render;











       if ST.Interval<>20 then ST.Interval:=20;
       ST.Enabled:=true;






end;


procedure   TMyFrame.circ_ok();
var
    RT1,RT2,A1,A2,A3,A4: array [0..1] of real;
    x,y:byte;
    valx,valy:real;
begin

   page_unext();


   x:=0;y:=1;
   RT1[x]:=VMov.BFixDown.X+0.5;
   RT1[y]:=VMov.BFixDown.Y+0.5;
   RT2[x]:=VMov.BmovReal.X+0.5;
   RT2[y]:=VMov.BmovReal.Y+0.5;

   valx:=((RT2[x]-RT1[x])*0.28);
   valy:=((RT2[y]-RT1[y])*0.28);
   A1[x]:=(rt2[x]-rt1[x])/2+ rt1[x];
   A1[y]:=rt1[y];
   A2[x]:=rt1[x];
   A2[y]:=(rt2[y]-rt1[y])/2+ rt1[y];
   A3[x]:=rt2[x];
   A3[y]:=(rt2[y]-rt1[y])/2+ rt1[y];
   A4[x]:=(rt2[x]-rt1[x])/2+ rt1[x];
   A4[y]:=rt2[y];

    cairo_set_source_rgb(Tundo[VUndo].CR,1,1,1);
    cairo_set_line_width(Tundo[VUndo].CR,1);
    cairo_set_antialias(Tundo[VUndo].CR,CAIRO_ANTIALIAS_NONE);

   cairo_move_to  (Tundo[VUndo].CR, A1[x], A1[y]);
   cairo_curve_to (Tundo[VUndo].CR, A1[x]-valx,A1[y], A2[x],A2[y]-valy, A2[x], A2[y]);
   cairo_curve_to (Tundo[VUndo].CR, A2[x],A2[y]+valy, A4[x]-valx,A4[y], A4[x], A4[y]);
   cairo_curve_to (Tundo[VUndo].CR, A4[x]+valx,A4[y], A3[x],A3[y]+valy, A3[x], A3[y]);
   cairo_curve_to (Tundo[VUndo].CR, A3[x],A3[y]-valy, A1[x]+valx,A1[y], A1[x], A1[y]);

   cairo_stroke(Tundo[VUndo].CR);





end;

procedure   TMyFrame.circ_end();

begin







end;









