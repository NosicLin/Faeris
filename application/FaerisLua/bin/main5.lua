
g_window:setSize(1024,800)
g_window:setCaption("FaerisGame")


g_render:setClearColor(Color(0,0,0))
g_render:clear(true)
g_render:swapBuffers()
g_render:setViewport(0,0,1024,800)
g_frame:setFPS(0)

mat=Matrix4()
--mat:makeOrthographic(-4,4,-4,4,1,100);
mat:makeFrustum(-4,4,-4,4,1,100);
g_render:setProjectionMatrix(mat);



g_render:clear(true)

dofile("test_scene_node.lua")

local function onFrameEnd(diff)
--	print( "update"..diff.."FPS:"..g_frame:getAvgFPS())

	g_render:clear(true)
	test_set_postion();
	g_render:swapBuffers();
end


g_render:translate(Vector3(0,0,-4))

local function onFrameUpdate(diff)

end

frame_listener=FrameListener()


frame_listener:registerUpdateFunc(onFrameUpdate)
frame_listener:registerEndFunc(onFrameEnd)


g_frame:addListener(frame_listener);


