font=FontBitmap:create("bmp.fnt");

quad=ColorQuad2D:create(200,200,Color(255,255,255))
quad:setZorder(-1)

label1=LabelBitmap:create(font)
label1:setBounds(400,100)

label2=LabelBitmap:create(font)

label2:setBounds(400,0);


label1:setTextAlign(LabelBitmap.TEXT_ALIGN_LEFT)
label1:setAlign(LabelBitmap.ALIGN_H_RIGHT,LabelBitmap.ALIGN_V_BOTTOM)



str="\tSome people say that true lovers are one soul that is separated when it's born and those two halves will always yearn to find their way back together.\n\n\t有人说“情侣”是灵魂转世时一分为二，此生都在寻找另一半。" 
str_nu=label1:setString(str)
f_utillog("str_nu=%d",str_nu);

label2:setString(str,str_nu)



label1:setPosition(400,400)
label2:setPosition(0,400)

quad:setPosition(400,400)

scene=Scene:create();

layer=Layer2D:create()
layer:add(label1);
layer:add(label2)

layer:add(quad);
layer:setViewArea(0,0,960,640)

layer:setSortMode(Layer2D.SORT_ORDER_Z)


scene:push(layer)
share:director():run(scene)





