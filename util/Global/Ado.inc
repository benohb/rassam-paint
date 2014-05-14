

             if Button=mbRight then MR:=1;
             if Button=mbMiddle then MM:=1;
             if Button=mbLeft then ML:=1;


             VMov.XmovReal.X:=x;
             VMov.XmovReal.y:=y;
             VMov.BmovReal.X:=( VMov.XmovReal.X  div zoom)+Scol_H^.Position ;
             VMov.BmovReal.y:=( VMov.XmovReal.Y  div zoom)+Scol_V^.Position ;
             VMov.XFixDown:=VMov.XmovReal;
             VMov.BFixDown:=VMov.BmovReal;
             VMov.BDiff.X:=0;
             VMov.BDiff.Y:=0;

             Scol_H^.Tag:=Scol_H^.Position;
             Scol_V^.Tag:=Scol_V^.Position;



