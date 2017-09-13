%hall filling
im=zeros(500);
    for i=1:500
        for j=1:500
            
            if abs(i-250)*abs(i-250)+abs(j-250)*abs(j-250)<=900 && abs(i-250)*abs(i-250)+abs(j-250)*abs(j-250)>=800
             im(i,j)=1;
            end  
        end
    end
    I =im;
img=im2bw(im);
subplot(1,2,1);
imshow(img);

[m,n]=size(img);
se=[0 1 0;1 1 1;0 1 0];
x=zeros(m,n);
x1=x;
x(265,251)=1;
com=imcomplement(img);

while x ne x1
	x1=imdilate(x,se);
	x1=x1.*com
end
filled=x1+img;
subplot(1,2,2);
imshow(filled);
