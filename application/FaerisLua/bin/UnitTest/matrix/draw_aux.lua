function draw_coord()

	--axis X
	g_render:drawLine(Vector3(-1.0,0,0),Vector3(1.0,0,0),2,Color(255,0,0));

	--arrow >
	g_render:drawLine(Vector3(0.95,0.05,0),Vector3(1.0,0,0),1,Color(255,0,0));
	g_render:drawLine(Vector3(0.95,-0.05,0),Vector3(1.0,0,0),1,Color(255,0,0));

	--label X
	g_render:drawLine(Vector3(1.0,0.05,0),Vector3(1.06,-0.05,0),1,Color(255,0,0));
	g_render:drawLine(Vector3(1.0,-0.05,0),Vector3(1.06,0.05,0),1,Color(255,0,0));



	--axis Y
	g_render:drawLine(Vector3(0,1,0),Vector3(0,-1.0,0),2,Color(0,255,0));

	--arrow >
	g_render:drawLine(Vector3(-0.05,0.95,0),Vector3(0,1.0,0),1,Color(0,255,0));
	g_render:drawLine(Vector3(0.05,0.95,0),Vector3(0,1.0,0),1,Color(0,255,0));

	--label Y
	g_render:drawLine(Vector3(0,1.01,0),Vector3(0,1.07,0),1,Color(0,255,0))
	g_render:drawLine(Vector3(-0.03,1.12,0),Vector3(0,1.07,0),1,Color(0,255,0))
	g_render:drawLine(Vector3(0.03,1.12,0),Vector3(0,1.07,0),1,Color(0,255,0))


	--axis Z
	g_render:drawLine(Vector3(0,0,-1.0),Vector3(0,0,1.0),2,Color(0,0,255));

end

