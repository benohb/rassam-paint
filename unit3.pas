unit Unit3;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls,
  Spin;

type

  { TForm2 }

  TForm2 = class(TForm)
    Button1: TButton;
    ComboBox1: TComboBox;
    Memo1: TMemo;
    SpinEdit1: TSpinEdit;
    procedure Button1Click(Sender: TObject);
    procedure ComboBox1Change(Sender: TObject);
    procedure ComboBox1GetItems(Sender: TObject);
    procedure ComboBox1Select(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure Memo1Change(Sender: TObject);
    procedure SpinEdit1Change(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end;

var
  Form2: TForm2;

implementation

{$R *.lfm}

{ TForm2 }

procedure TForm2.Button1Click(Sender: TObject);
begin
  Form2.Close;

end;

procedure TForm2.ComboBox1Change(Sender: TObject);
begin
  Memo1.Font.Name:=ComboBox1.Items[ComboBox1.ItemIndex];
end;

procedure TForm2.ComboBox1GetItems(Sender: TObject);
begin

end;

procedure TForm2.ComboBox1Select(Sender: TObject);
begin
  Memo1.OnChange(nil);
end;

procedure TForm2.FormCreate(Sender: TObject);
begin
     ComboBox1.Items := Screen.Fonts;
     ComboBox1.ItemIndex:=Screen.Fonts.IndexOf('Sans');
      SpinEdit1.Value:=16;
end;

procedure TForm2.FormShow(Sender: TObject);
begin

end;

procedure TForm2.Memo1Change(Sender: TObject);
begin

end;

procedure TForm2.SpinEdit1Change(Sender: TObject);
begin
      Memo1.OnChange(nil);
end;

end.

