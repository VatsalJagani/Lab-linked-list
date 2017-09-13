

    im=zeros(500,500);
   
    for i=1:500
        for j=1:500
            
            if abs(i-250)*abs(i-250)+abs(j-250)*abs(j-250)<=900 && abs(i-250)*abs(i-250)+abs(j-250)*abs(j-250)>=800
             im(i,j)=1;
            end  
        end
    end
    I =im;
imshow(I);
    
    
    
    
    
    
    
   F = imfill(I,'holes');

    
    bw = bwlabel(I);
    rp = regionprops(bw,'FilledArea','PixelIdxList');
    indexesOfHoles = [rp.FilledArea]<150;   
    pixelsNotToFill = vertcat(rp(indexesOfHoles).PixelIdxList); 
    F(pixelsNotToFill) = 0;
    figure;imshow(F);

    
    bw1 = bwlabel(F,4);
    rp = regionprops(bw1,'FilledArea','PixelIdxList');
    indexesOfHoles1 = [rp.FilledArea]<150;
    pixelListToRemove = vertcat(rp(indexesOfHoles1).PixelIdxList);
    F(pixelListToRemove) = 0;

    figure;imshow(F);
