-- 有三个层，底层放个背景，中层就一个back按钮，上层为游戏

local chPlayLabel={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"}

local function LayerBK_New()
	layer = Layer2D:create()
	layer:setViewArea(0, 0, 960, 640)
	quad2dWM = Quad2D:create("textures/background.png", Rect2D(0, 0, 960, 640))
	layer:add(quad2dWM)
	return layer
end

local function LayerBack_TouchEnd(selfLayer, x, y)
	x, y = selfLayer:toLayerCoord(x, y)
	if selfLayer.data.buttonBack:hit2D(x, y) then
		-- 退出这个场景
		local director = share:director()
		director:pop()
		return true
	end
	return false
end

local function LayerBack_New()
	local layer = Layer2D:create()
	layer:setViewArea(0, 0, 960, 640)
	layer:setTouchEnabled(true)
	local font = FontTTF:create("simsun.ttc", 60)
	local buttonBack = LabelTTF:create("Back", font)
	buttonBack:setPosition(10, 650)
	buttonBack:setColor(Color.WHITE)
	layer:add(buttonBack)
	layer.data = {}
	layer.data.buttonBack = buttonBack
	layer.data.onTouchEnd = LayerBack_TouchEnd
	return layer
end

local function PlayLabel_New()
	local randNum = math.random(1, #chPlayLabel)
	print(chPlayLabel[randNum])
	local font = FontTTF:create("simsun.ttc", math.random(40, 80))
	local label = LabelTTF:create(chPlayLabel[randNum], font)
	label.data = {}
	label.data.x = math.random(1, 960)
	label.data.y = math.random(1, 640)
	label.data.speedX = math.random(-5, 5) * 15
	label.data.speedY = math.random(-5, 5) * 15
	
	label:setPosition(label.data.x, label.data.y)
	label:setAlign(LabelTTF.ALIGN_H_CENTER,LabelTTF.ALIGN_V_CENTER)
	return label
end

local function LayerPlay_New()
	local layer = Layer2D:create()
	layer:setViewArea(0, 0, 960, 640)
	layer:setTouchEnabled(true)
	layer.data = {}
	-- 初始化一下游戏中用到的字母
	layer.data.labels = {}
	for i = 0, 9 do
		local label = PlayLabel_New()
		layer.data.labels[label] = label
		layer:add(label)
	end
	layer.data.onTouchEnd = function (selfLayer, x, y)
		return false
	end

	layer.data.onUpdate = function (selfLayer, dt)
		layer:update(dt)
		local speedMul = dt / 1000
		local labels = selfLayer.data.labels -- 为了方便书写
		for key, value in pairs(labels) do
			if key.data.x < 0 and key.data.speedX < 0 then
				key.data.speedX = -key.data.speedX
			elseif key.data.x > 960 and key.data.speedX > 0 then
				key.data.speedX = -key.data.speedX
			end
			
			if key.data.y < 0 and key.data.speedY < 0 then
				key.data.speedY = -key.data.speedY
			elseif key.data.y > 640 and key.data.speedY > 0 then
				key.data.speedY = -key.data.speedY
			end
			
			key.data.x = key.data.x + key.data.speedX * speedMul
			key.data.y = key.data.y + key.data.speedY * speedMul
			key:setPosition(key.data.x, key.data.y)
		end
	end

	return layer
end

function ScenePlay_New()
	local scene = Scene:create()
	local layer = LayerBK_New()
	scene:push(layer)
	local layer = LayerBack_New()
	scene:push(layer)
	local layer = LayerPlay_New()
	scene:push(layer)
	return scene
end