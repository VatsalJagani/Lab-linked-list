img=imread('cameraman.tif');
img=im2bw(img,0.5);
se=ones(7);


%opening
erodedI = imerode(img,se);
dilatedI = imdilate(erodedI,se);
subplot(2,2,1);
imshow(dilatedI)
op=imopen(img,se);
subplot(2,2,2);
imshow(op)


%closing
dilatedI = imdilate(img,se);
erodedI = imerode(dilatedI,se);
subplot(2,2,3);
imshow(erodedI)
cl=imclose(img,se);
subplot(2,2,4);
imshow(cl)
