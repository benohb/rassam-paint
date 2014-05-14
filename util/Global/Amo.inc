    if ssRight  in Shift then MR:=1 else MR:=0;
    if ssMiddle in Shift then MM:=1 else MM:=0;
    if ssLeft   in Shift then ML:=1 else ML:=0;






        VMov.XmovReal.X:=X;
        VMov.XmovReal.Y:=Y;
        VMov.BmovReal.X:=( VMov.XmovReal.X  div zoom)+Scol_H^.Position ;
        VMov.BmovReal.y:=( VMov.XmovReal.Y  div zoom)+Scol_V^.Position ;
        //
        //
        VMov.BDiff.X:=VMov.BmovReal.X-VMov.BFixDown.X ;
        VMov.BDiff.Y:=VMov.BmovReal.Y-VMov.BFixDown.Y ;
        //
        //
        Form1.IdleTimer2.Enabled:=true;

        if  ssMiddle in Shift then begin
        Scol_H^.Tag:= Scol_H^.Position-VMov.BDiff.X;
        Scol_V^.Tag:= Scol_v^.Position-VMov.BDiff.Y;
        if Scol_H^.Tag <0 then Scol_H^.Tag:=0;
        if Scol_V^.Tag <0 then Scol_V^.Tag:=0;
        if Scol_H^.Tag >Scol_H^.Max then Scol_H^.Tag :=Scol_H^.Max;
        if Scol_V^.Tag >Scol_V^.Max then Scol_V^.Tag :=Scol_V^.Max;
        IdleTimer1.Enabled:=true;
        exit();
        end;  
