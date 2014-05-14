program project1;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Interfaces, // this includes the LCL widgetset
  Forms, printer4lazarus, Unit1, Bitmapraw, Unit3, printV, abot;

{$R *.res}


begin
  Application.Title:='Rassam-paint';
  RequireDerivedFormResource := True;
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.CreateForm(TForm2, Form2);
  Application.CreateForm(TPrintV, PrintVFo);
  Application.CreateForm(TForm4, about);
  Application.Run;
end.

