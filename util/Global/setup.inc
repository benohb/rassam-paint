

procedure TMyFrame.test();
   const hb:byte=0;
//  var
 // bitim:TFastBitmap;
   {
  I: LongInt;

  // this is one level image container

  // this is multi level image container
  MImg: TMultiImage;
  }
var dlg:TfpgFileDialog ;


begin


   {
       InitImage(Img);
  // create 8 bit grayscale image
  NewImage(100, 100, ifGray8, Img);
  // draw diagonal line by direct writing to image's memory
  for I := 0 to Img.Width - 1 do
    PByte(@PByte(Img.Bits)[I * Img.Width])[I] := 128;
  // save image to file
  SaveImageToFile('/tmp/1.bmp', Img);
  // memory occupied by image is freed
  FreeImage(Img);

        w



    InitImage(Img);
   NewImage(cairo_image_surface_get_width(fc1),
   cairo_image_surface_get_height(fc1), ifA8R8G8B8, Img);

   for I := 0 to (Img.Width-1) * (Img.Height-1) do
   Pinteger(Img.Bits)[I]:=Pinteger(cairo_image_surface_get_data(fc1))[i];


   SaveImageToFile('/tmp/1.jpeg', Img);

    FreeImage(Img);


  //  SImg := TSingleImage.CreateFromParams(cairo_image_surface_get_width(fc1),
   //  cairo_image_surface_get_height(fc1), ifA8R8G8B8);

    InitImage(Img);
    InitImage(Img2);
   NewImage(cairo_image_surface_get_width(fc0),
   cairo_image_surface_get_height(fc0), ifA8R8G8B8, Img);

      GlobalMetadata.AddMetaItem('AnimationLoops',5,1);

  // Img.Format := ifIndex8;



   NewImage(cairo_image_surface_get_width(fc1),
   cairo_image_surface_get_height(fc1), ifA8R8G8B8, Img2);

    Move(cairo_image_surface_get_data(fc0)^,Img.Bits^,Img.Size);
    Move(cairo_image_surface_get_data(fc1)^,Img2.Bits^,Img2.Size);


   //Img2.Format := ifIndex8;



      writeln('TMyFrame.tes ',GlobalMetadata.MetaItemCount );


    MImg := TMultiImage.Create;

    MImg.AddImage(Img);
    MImg.AddImage(Img2);

     //  SetOption(Gifspeedpram, 1);
     //  SetOption(GifloopsNet, 10);
  // MImg.SaveToFile('/tmp/1.gif');
    MImg.SaveMultiToFile('/tmp/1.gif');
   //TGIFFileFormat;
     // TPNGFileFormat
     //ImagingGIFLoadAnimated
   FreeImage(Img);
   FreeImage(Img2);


  MImg.Free;

  }




 ;




end;



















