function draw_coord()

	--axis X
	g_render:drawLine(Vector3(-1.0,0,0),Vector3(1.0,0,0),2,Color(255,0,0));

	--arrow >
	g_render:drawLine(Vector3(0.95,0.05,0),Vector3(1.0,0,0),1,Color(255,0,0));
	g_render:drawLine(Vector3(0.95,-0.05,0),Vector3(1.0,0,0),1,Color(255,0,0));

	g_render:drawLine(Vector3(0.95,0,0.05),Vector3(1.0,0,0),1,Color(255,0,0));
	g_render:drawLine(Vector3(0.95,0,-0.05),Vector3(1.0,0,0),1,Color(255,0,0));

	--label X
	g_render:drawLine(Vector3(1.0,0.05,0),Vector3(1.06,-0.05,0),1,Color(255,0,0));
	g_render:drawLine(Vector3(1.0,-0.05,0),Vector3(1.06,0.05,0),1,Color(255,0,0));



	--axis Y
	g_render:drawLine(Vector3(0,1,0),Vector3(0,-1.0,0),2,Color(0,255,0));

	--arrow >
	g_render:drawLine(Vector3(-0.05,0.95,0),Vector3(0,1.0,0),1,Color(0,255,0));
	g_render:drawLine(Vector3(0.05,0.95,0),Vector3(0,1.0,0),1,Color(0,255,0));

	g_render:drawLine(Vector3(0,0.95,-0.05),Vector3(0,1.0,0),1,Color(0,255,0));
	g_render:drawLine(Vector3(0,0.95,0.05),Vector3(0,1.0,0),1,Color(0,255,0));

	--label Y
	g_render:drawLine(Vector3(0,1.01,0),Vector3(0,1.07,0),1,Color(0,255,0))
	g_render:drawLine(Vector3(-0.03,1.12,0),Vector3(0,1.07,0),1,Color(0,255,0))
	g_render:drawLine(Vector3(0.03,1.12,0),Vector3(0,1.07,0),1,Color(0,255,0))


	--axis Z
	g_render:drawLine(Vector3(0,0,-1.0),Vector3(0,0,1.0),2,Color(0,0,255));

	--arrow >
	g_render:drawLine(Vector3(0.05,0,0.95),Vector3(0,0,1.0),1,Color(0,0,255));
	g_render:drawLine(Vector3(-0.05,0,0.95),Vector3(0,0,1.0),1,Color(0,0,255));
	g_render:drawLine(Vector3(0,0.05,0.95),Vector3(0,0,1.0),1,Color(0,0,255));
	g_render:drawLine(Vector3(0,-0.05,0.95),Vector3(0,0,1.0),1,Color(0,0,255));

	--label Z


end

function draw_F()
	g_render:drawLine(Vector3(0,0,0),Vector3(0,1.0,0),1,Color(0,255,255));
	g_render:drawLine(Vector3(0,1.0,0),Vector3(0.3,1.0,0),1,Color(0,255,255));
	g_render:drawLine(Vector3(0,0.7,0),Vector3(0.3,0.7,0),1,Color(0,255,255));

end


function draw_test_make_translate()
	--left x
	
	g_render:pushMatrix()
	g_render:translate(Vector3(0,0,-13))
	g_render:rotate(Vector3(1,0,0),20);
	g_render:rotate(Vector3(0,1,0),-45);
	draw_coord()
	mat=Matrix4()
	g_render:pushMatrix()
	mat:makeTranslate(0.5,0,0)
	g_render:mulMatrix(mat);
	draw_F();
	g_render:popMatrix();


	--right x
	g_render:pushMatrix()
	mat:makeTranslate(-0.5,0,0)
	g_render:mulMatrix(mat);
	draw_F();
	g_render:popMatrix();


	--up y
	g_render:pushMatrix()
	mat:makeTranslate(0,0.5,0);
	g_render:mulMatrix(mat);
	draw_F();
	g_render:popMatrix()

	--down y
	g_render:pushMatrix()
	mat:makeTranslate(0,-1.5,0);
	g_render:mulMatrix(mat);
	draw_F();
	g_render:popMatrix()

	--forward z 
	g_render:pushMatrix()
	mat:makeTranslate(0,0,1.0);
	g_render:mulMatrix(mat);
	draw_F();
	g_render:popMatrix()

	--back z
	g_render:pushMatrix()
	mat:makeTranslate(0,0,-1.0);
	g_render:mulMatrix(mat);
	draw_F();
	g_render:popMatrix()

	--all x,y,z
	g_render:pushMatrix()
	mat:makeTranslate(1.2,1.5,0.7);
	g_render:mulMatrix(mat);
	draw_F();
	g_render:popMatrix()
	g_render:popMatrix()

end

make_rotate_anglex=0
make_rotate_angley=0
make_rotate_anglez=0
make_rotate_anglex_diff=0.01
make_rotate_angley_diff=0.005
make_rotate_anglez_diff=0.0025
function draw_test_make_rotate()

	if make_rotate_anglex>1.0 then
		make_rotate_anglex_diff=0.01
	elseif make_rotate_anglex<-1.0 then 
		make_rotate_anglex_diff=0.01
	end 

	if make_rotate_angley>1.0 then
		make_rotate_angley_diff=-0.005
	elseif make_rotate_angley<-1.0 then 
		make_rotate_angley_diff=0.005
	end 

	if make_rotate_anglez>1.0 then
		make_rotate_anglez_diff=-0.0025
	elseif make_rotate_anglez<-1.0 then 
		make_rotate_anglez_diff=0.0025
	end 


	make_rotate_anglex=make_rotate_anglex+make_rotate_anglex_diff
	make_rotate_angley=make_rotate_angley+make_rotate_angley_diff
	make_rotate_anglez=make_rotate_anglez+make_rotate_anglez_diff

	mat=Matrix4()

	--single axis rotate 
	g_render:pushMatrix()
	g_render:translate(Vector3(0,0,-13))
	g_render:rotate(Vector3(1,0,0),20);
	g_render:rotate(Vector3(0,1,0),-45);


	g_render:pushMatrix()
	g_render:translate(Vector3(-1.0,0.8,0))
	draw_coord()
	g_render:pushMatrix()
	g_render:translate(Vector3(1,0,0));
	draw_F()
	mat:makeRotateX(30)
	g_render:mulMatrix(mat);
	draw_F()
	g_render:popMatrix()

	g_render:pushMatrix()
	g_render:translate(Vector3(0,-1,0));
	draw_F()
	mat:makeRotateY(30)
	g_render:mulMatrix(mat);
	draw_F()
	g_render:popMatrix()

	g_render:pushMatrix()
	g_render:translate(Vector3(0,0,1));
	draw_F()
	mat:makeRotateZ(30)
	g_render:mulMatrix(mat);
	draw_F()
	g_render:popMatrix()
	g_render:popMatrix()
	g_render:popMatrix()


	--axis rotate 
	mat:makeRotateAxis(1,1,1,30)
	g_render:pushMatrix()
	g_render:translate(Vector3(1.0,-0.8,0))
	g_render:translate(Vector3(0,0,-13))
	g_render:rotate(Vector3(1,0,0),20);
	g_render:rotate(Vector3(0,1,0),-45);

	draw_coord()
	draw_F()

	for i=1,360,20 do 
		g_render:pushMatrix()
		mat:makeRotateAxis(make_rotate_anglex,make_rotate_angley,make_rotate_anglez,i)
		g_render:mulMatrix(mat)
		draw_F()
		g_render:popMatrix()
	end

	g_render:popMatrix()

	g_render:pushMatrix()
	g_render:translate(Vector3(-1.0,-0.8,0))
	g_render:translate(Vector3(0,0,-13))
	g_render:rotate(Vector3(1,0,0),20);
	g_render:rotate(Vector3(0,1,0),-45);

	draw_coord()
	draw_F()

	for i=1,360,20 do 
		g_render:pushMatrix()
		g_render:rotate(Vector3(make_rotate_anglex,make_rotate_angley,make_rotate_anglez),i)
		draw_F()
		g_render:popMatrix()
	end

	g_render:popMatrix()

end


euler_x=0
euler_y=0
euler_z=0

function draw_test_make_rotate_from_euler()

	mat=Matrix4()
	euler_x=euler_x+0.1
	euler_y=euler_y+0.2
	euler_z=euler_z+0.3


	-- opengl default 
	g_render:pushMatrix()
	g_render:translate(Vector3(-1.0,0,0))
	g_render:translate(Vector3(0,0,-13))
	g_render:rotate(Vector3(1,0,0),20);
	g_render:rotate(Vector3(0,1,0),-45);
	g_render:scale(Vector3(0.8,0.8,0.8))
	draw_coord()

	--euler x_y_z
	g_render:pushMatrix()
	g_render:translate(Vector3(1.0,0,0))
	g_render:rotate(Vector3(1,0,0),euler_x)
	g_render:rotate(Vector3(0,1,0),euler_y)
	g_render:rotate(Vector3(0,0,1),euler_z)
	draw_F()
	g_render:popMatrix()

	--euler x_z_y
	g_render:pushMatrix()
	g_render:translate(Vector3(-1.0,0,0))
	g_render:rotate(Vector3(1,0,0),euler_x)
	g_render:rotate(Vector3(0,0,1),euler_z)
	g_render:rotate(Vector3(0,1,0),euler_y)
	draw_F()
	g_render:popMatrix()

	--euler y_x_z
	g_render:pushMatrix()
	g_render:translate(Vector3(0.0,1.0,0))
	g_render:rotate(Vector3(0,1,0),euler_y)
	g_render:rotate(Vector3(1,0,0),euler_x)
	g_render:rotate(Vector3(0,0,1),euler_z)
	draw_F()
	g_render:popMatrix()

	--euler_y_z_x
	g_render:pushMatrix()
	g_render:translate(Vector3(0.0,-1.0,0))
	g_render:rotate(Vector3(0,1,0),euler_y)
	g_render:rotate(Vector3(0,0,1),euler_z)
	g_render:rotate(Vector3(1,0,0),euler_x)
	draw_F()
	g_render:popMatrix()

	--euler z_x_y
	g_render:pushMatrix()
	g_render:translate(Vector3(0.0,0.0,1.0))
	g_render:rotate(Vector3(0,0,1),euler_z)
	g_render:rotate(Vector3(1,0,0),euler_x)
	g_render:rotate(Vector3(0,1,0),euler_y)
	draw_F()
	g_render:popMatrix()

	--euler_z_y_x
	g_render:pushMatrix()
	g_render:translate(Vector3(0.0,0.0,-1.0))
	g_render:rotate(Vector3(0,0,1),euler_z)
	g_render:rotate(Vector3(0,1,0),euler_y)
	g_render:rotate(Vector3(1,0,0),euler_x)
	draw_F()
	g_render:popMatrix()

	g_render:popMatrix()



	-- faeris matrix 
	g_render:pushMatrix()
	g_render:translate(Vector3(1.0,0,0))
	g_render:translate(Vector3(0,0,-13))
	g_render:rotate(Vector3(1,0,0),20);
	g_render:rotate(Vector3(0,1,0),-45);
	draw_coord()


	--euler x_y_z
	g_render:pushMatrix()
	g_render:translate(Vector3(1.0,0,0))
	mat:makeRotateFromEuler(euler_x,euler_y,euler_z,FS.EULER_XYZ)
	g_render:mulMatrix(mat)
	draw_F()
	g_render:popMatrix()

	--euler x_z_y
	g_render:pushMatrix()
	g_render:translate(Vector3(-1.0,0,0))
	mat:makeRotateFromEuler(euler_x,euler_y,euler_z,FS.EULER_XZY)
	g_render:mulMatrix(mat)
	draw_F()
	g_render:popMatrix()


	--euler y_x_z
	g_render:pushMatrix()
	g_render:translate(Vector3(0.0,1.0,0))
	mat:makeRotateFromEuler(euler_x,euler_y,euler_z,FS.EULER_YXZ)
	g_render:mulMatrix(mat)
	draw_F()
	g_render:popMatrix()

	--euler y_z_x
	g_render:pushMatrix()
	g_render:translate(Vector3(0.0,-1.0,0))
	mat:makeRotateFromEuler(euler_x,euler_y,euler_z,FS.EULER_YZX)
	g_render:mulMatrix(mat)
	draw_F()
	g_render:popMatrix()

	--euler z_x_y
	g_render:pushMatrix()
	g_render:translate(Vector3(0.0,0.0,1.0))
	mat:makeRotateFromEuler(euler_x,euler_y,euler_z,FS.EULER_ZXY)
	g_render:mulMatrix(mat)
	draw_F()
	g_render:popMatrix()

	--euler z_y_x
	g_render:pushMatrix()
	g_render:translate(Vector3(0.0,0.0,-1.0))
	mat:makeRotateFromEuler(euler_x,euler_y,euler_z,FS.EULER_ZYX)
	g_render:mulMatrix(mat)
	draw_F()
	g_render:popMatrix()

	g_render:popMatrix()
end

transform_posx=0
transform_posy=0
transform_posz=0

t_posx_diff=0.001 
t_posy_diff=0.002 
t_posz_diff=0.003

transform_anglex=0
transform_angley=0
transform_anglez=0

transform_scalex=0
transform_scaley=0
transform_scalez=0

function draw_test_transform()

	if transform_posx>1.0 then 
		t_posx_diff=-0.01 
	elseif transform_posx<-1.0 then 
		t_posx_diff=0.01
	end 

	if transform_posy>1.0 then 
		t_posy_diff=-0.01 
	elseif  transform_posy<-1.0 then 
		t_posy_diff=0.01
	end 

	if transform_posz>1.0 then 
		t_posz_diff=-0.01 
	elseif  transform_posz<-1.0 then 
		t_posz_diff=0.01
	end 





	transform_posx=transform_posx+t_posx_diff
	transform_posy=transform_posy+t_posy_diff
	transform_posz=transform_posz+t_posz_diff

	transform_anglex=transform_anglex+0.1
	transform_angley=transform_angley+0.2
	transform_anglez=transform_anglez+0.3

	--opengl 
	g_render:pushMatrix()
	g_render:translate(Vector3(-1.0,0,0))
	g_render:translate(Vector3(0,0,-13))
	g_render:rotate(Vector3(1,0,0),20);
	g_render:rotate(Vector3(0,1,0),-45);
	draw_coord()


	g_render:translate(Vector3(transform_posx/3,transform_posy/3,transform_posz/3))
	g_render:rotate(Vector3(1,0,0),transform_anglex/2)
	g_render:rotate(Vector3(0,1,0),transform_angley/2)
	g_render:rotate(Vector3(0,0,1),transform_anglez/2)
	g_render:translate(Vector3(transform_posx/3,transform_posy/3,transform_posz/3))
	g_render:rotate(Vector3(0,1,0),transform_angley/2)
	g_render:rotate(Vector3(1,0,0),transform_anglex/2)
	g_render:rotate(Vector3(0,0,1),transform_anglez/2)
	g_render:translate(Vector3(transform_posx/3,transform_posy/3,transform_posz/3))
	g_render:rotate(Vector3(transform_posx,transform_posy,transform_posz),(transform_anglex+transform_posy+transform_posz)/2)


	draw_F()
	g_render:popMatrix();


	--faeris 
	mat=Matrix4()
	g_render:pushMatrix()
	g_render:translate(Vector3(1.0,0,0))
	g_render:translate(Vector3(0,0,-13))
	g_render:rotate(Vector3(1,0,0),20);
	g_render:rotate(Vector3(0,1,0),-45);
	draw_coord()

	mat:makeTranslate(transform_posx/3,transform_posy/3,transform_posz/3)

	mat:rotateX(transform_anglex/2)
	mat:rotateY(transform_angley/2)
	mat:rotateZ(transform_anglez/2)
	mat:translate(transform_posx/3,transform_posy/3,transform_posz/3)
	mat:rotateY(transform_angley/2)
	mat:rotateX(transform_anglex/2)
	mat:rotateZ(transform_anglez/2)
	mat:translate(transform_posx/3,transform_posy/3,transform_posz/3)
	mat:rotateByAxis(transform_posx,transform_posy,transform_posz,(transform_anglex+transform_posy+transform_posz)/2)

	g_render:mulMatrix(mat)
	draw_F()

	g_render:popMatrix();


end 




function draw_test_mul()

	if transform_posx>1.0 then 
		t_posx_diff=-0.01 
	elseif transform_posx<-1.0 then 
		t_posx_diff=0.01
	end 

	if transform_posy>1.0 then 
		t_posy_diff=-0.01 
	elseif  transform_posy<-1.0 then 
		t_posy_diff=0.01
	end 

	if transform_posz>1.0 then 
		t_posz_diff=-0.01 
	elseif  transform_posz<-1.0 then 
		t_posz_diff=0.01
	end 





	transform_posx=transform_posx+t_posx_diff
	transform_posy=transform_posy+t_posy_diff
	transform_posz=transform_posz+t_posz_diff

	transform_anglex=transform_anglex+0.1
	transform_angley=transform_angley+0.2
	transform_anglez=transform_anglez+0.3

	--opengl 
	g_render:pushMatrix()
	g_render:translate(Vector3(-1.0,0,0))
	g_render:translate(Vector3(0,0,-13))
	g_render:rotate(Vector3(1,0,0),20);
	g_render:rotate(Vector3(0,1,0),-45);
	draw_coord()


	g_render:translate(Vector3(transform_posx/3,transform_posy/3,transform_posz/3))
	g_render:rotate(Vector3(1,0,0),transform_anglex/2)
	g_render:rotate(Vector3(0,1,0),transform_angley/2)
	g_render:rotate(Vector3(0,0,1),transform_anglez/2)
	g_render:translate(Vector3(transform_posx/3,transform_posy/3,transform_posz/3))
	g_render:rotate(Vector3(0,1,0),transform_angley/2)
	g_render:rotate(Vector3(1,0,0),transform_anglex/2)
	g_render:rotate(Vector3(0,0,1),transform_anglez/2)
	g_render:translate(Vector3(transform_posx/3,transform_posy/3,transform_posz/3))
	--g_render:rotate(Vector3(transform_posx,transform_posy,transform_posz),(transform_anglex+transform_posy+transform_posz)/2)

	draw_F()
	g_render:popMatrix();


	--faeris 
	mat=Matrix4()
	g_render:pushMatrix()
	g_render:translate(Vector3(1.0,0,0))
	g_render:translate(Vector3(0,0,-13))
	g_render:rotate(Vector3(1,0,0),20);
	g_render:rotate(Vector3(0,1,0),-45);
	draw_coord()

	mat_right=Matrix4()
	mat:makeTranslate(transform_posx/3,transform_posy/3,transform_posz/3)

	mat_right:makeRotateX(transform_anglex/2)
	mat:mul(mat_right)

	mat_right:makeRotateY(transform_angley/2)
	mat:mul(mat_right)

	mat_right:makeRotateZ(transform_anglez/2)
	mat:mul(mat_right)

	mat_right:makeTranslate(transform_posx/3,transform_posy/3,transform_posz/3)
	mat:mul(mat_right)

	mat_right:makeRotateY(transform_angley/2)
	mat:mul(mat_right)

	mat_right:makeRotateX(transform_anglex/2)
	mat:mul(mat_right)

	mat_right:makeRotateZ(transform_anglez/2)
	mat:mul(mat_right)

	mat_right:makeTranslate(transform_posx/3,transform_posy/3,transform_posz/3)
	mat:mul(mat_right)

	g_render:mulMatrix(mat)

	--mat:rotateByAxis(transform_posx,transform_posy,transform_posz,(transform_anglex+transform_posy+transform_posz)/2)

	draw_F()

	g_render:popMatrix();


end 






















