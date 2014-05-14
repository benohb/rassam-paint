unit printV;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, PrintersDlgs, Forms, Controls, Graphics, Dialogs,
  StdCtrls, ExtCtrls, Spin, Printers;

type

  { TPrintV }

  TPrintV = class(TForm)
    Button1: TButton;
    Button2: TButton;
    ComboBox1: TComboBox;
    Label1: TLabel;
    PageSetupDialog1: TPageSetupDialog;
    RadioGroup1: TRadioGroup;
    printpic:tbitmap;
    SpinEdit1: TSpinEdit;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure ComboBox1GetItems(Sender: TObject);
    procedure ComboBox1Select(Sender: TObject);
    procedure FormClose(Sender: TObject; var CloseAction: TCloseAction);
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure Image2Click(Sender: TObject);
    procedure RadioGroup1Click(Sender: TObject);
    procedure Shape2Paint(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end;

var
  PrintVFo: TPrintV;
  bis:Single;


implementation
 uses Unit1;
{$R *.lfm}

{ TPrintV }

procedure TPrintV.FormCreate(Sender: TObject);
begin

end;

procedure TPrintV.Button1Click(Sender: TObject);
begin

PageSetupDialog1.Execute;

end;

procedure TPrintV.Button2Click(Sender: TObject);
begin
  Printer.Orientation:=TPrinterOrientation(RadioGroup1.ItemIndex);


   with Printer do
      try
          BeginDoc;

            Canvas.StretchDraw(rect(0,0,printpic.Width*SpinEdit1.Value ,printpic.Height*SpinEdit1.Value), printpic);



      finally
          EndDoc;
      end;

  self.Close;

end;

procedure TPrintV.ComboBox1GetItems(Sender: TObject);
begin

end;

procedure TPrintV.ComboBox1Select(Sender: TObject);
begin
  Printer.PrinterIndex:=ComboBox1.ItemIndex;
end;

procedure TPrintV.FormClose(Sender: TObject; var CloseAction: TCloseAction);
begin

end;

procedure TPrintV.FormShow(Sender: TObject);

begin
  if Printer.Printers.Count >0 then begin

    ComboBox1.Items:=Printer.Printers;
    ComboBox1.ItemIndex:=0;
  end;





end;

procedure TPrintV.Image2Click(Sender: TObject);
begin

end;

procedure TPrintV.RadioGroup1Click(Sender: TObject);
begin
  FormShow(nil);
end;

procedure TPrintV.Shape2Paint(Sender: TObject);
begin

end;

end.

