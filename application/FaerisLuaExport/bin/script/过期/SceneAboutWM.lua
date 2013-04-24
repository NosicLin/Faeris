
local textAboutList = 
{
	{
		x = 320,
		y = 500,
		size = 20,
		color = Color.RED,
		text = "HaHa",
	},
	{
		x = 320,
		y = 300,
		size = 40,
		color = Color.WHITE,
		text = "This is a Test",
	},
	{
		x = 320,
		y = -300,
		size = 50,
		color = Color.GREEN,
		text = "Surprise!",
	},
}

local function MsgTouchBFun(selfLayer, x, y)
-- 	x, y = selfLayer:toLayerCoord(x, y)
-- 	print("MsgTouchBFun(selfLayer, x, y) " .. y)
	selfLayer.data.lastY = y
	return true
end

local function MsgTouchMFun(selfLayer, x, y)
-- 	x, y = selfLayer:toLayerCoord(x, y) -- 如果不转换坐标则都是左下角为(0,0)，右上角为(1,1)
-- 	print("MsgTouchMFun(selfLayer, x, y) " .. y)
	local data = selfLayer.data -- 为了方便书写
	data.curY = data.curY + (data.lastY - y) * 640
	
	if data.curY > 132 then
		data.curY = 132
	elseif data.curY < -777 then
		data.curY = -777
	end
	print("data.curY " .. data.curY)
	data.lastY = y
	selfLayer:setViewArea(0, data.curY, 960, 640)
-- 	data.lastY = y + (data.lastY - y)
	return true
end

local function LayerMsg()
	local layerWM = Layer2D:create()
	layerWM.data = {}
	layerWM:setTouchEnabled(true)
	layerWM:setViewArea(0, 0, 960, 640)
	
	for i = 1, #textAboutList do
		local font = FontTTF:create("simsun.ttc", textAboutList[i].size)
		local text = LabelTTF:create(textAboutList[i].text, font)
		text:setColor(textAboutList[i].color)
		text:setPosition(textAboutList[i].x, textAboutList[i].y)
		layerWM:add(text)
	end
	
	layerWM.data.curY = 0
	layerWM.data.lastY = 0
	layerWM.data.onTouchBegin = MsgTouchBFun
	layerWM.data.onTouchMove = MsgTouchMFun
-- 	layerWM.data.onTouchEnd = MsgTouchEFun
	
	return layerWM
end

local function BackToMainMenuFun(selfLayer, x, y)
	local x, y = selfLayer:toLayerCoord(x, y)
	if selfLayer.data.textBack:hit2D(x, y) then
		local directorWM = share:director()
		directorWM:pop()
		return true
	end
	return false
end

local function BackMainMenuMov(selfLayer, x, y)
	return false
end

function LayerBack()
	local layerWM = Layer2D:create()
	layerWM:setTouchEnabled(true)
	layerWM:setViewArea(0, 100, 960, 640)
	local font = FontTTF:create("simsun.ttc", 80)
	local textBack = LabelTTF:create("<<Back", font)

	textBack:setPosition(150, 600)
	textBack:setAlign(LabelTTF.ALIGN_H_CENTER, LabelTTF.ALIGN_V_CENTER)
	textBack:setColor(Color.RED)
	layerWM:add(textBack)
	
	layerWM.data = {}
	layerWM.data.textBack = textBack
	layerWM.data.onTouchBegin = BackToMainMenuFun
	layerWM.data.onTouchMove = BackMainMenuMov
	layerWM.data.onTouchEnd = BackMainMenuMov
	
	return layerWM
end

function SceneAbout()
	local sceneWM = Scene:create()
	local layerBack = LayerBack()
	local layerMsg = LayerMsg()
	
	sceneWM:push(layerMsg)
	sceneWM:push(layerBack)
	
	return sceneWM
end