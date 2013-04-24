
local function MainMenuLayoutEnter(selfLayer)
	print("run MainMenuLayoutEnter(selfLayer)")
	selfLayer.data.quad2DPlay:setVisible(false)
	selfLayer.data.quad2DQuit:setVisible(false)
	selfLayer.data.quad2DAbout:setVisible(false)
	selfLayer.data.spriteBK:setAnimation("default")
	selfLayer.data.spriteBK:startAnimation(Sprite2D.ANIM_END)
end

local function MainMenuLayoutUpdate(selfLayer, dt)
	selfLayer:update(dt) -- 没有这句貌似精灵动画不播
	local total_frame = selfLayer.data.spriteBK:getTotalFrame()
	local cur_frame = selfLayer.data.spriteBK:getCurFrame()
	if total_frame - 1 == cur_frame then
		-- print("主菜单可以点击了")
		selfLayer.data.quad2DPlay:setVisible(true)
		selfLayer.data.quad2DQuit:setVisible(true)
		selfLayer.data.quad2DAbout:setVisible(true)
		selfLayer:setTouchEnabled(true)
	else
		print("dt" .. dt)
		print(total_frame .. "  " .. cur_frame)
	end
end

local function MainMenuTouchBFun(selfLayer, x, y) -- self 为 Layer2D
	print("run MainMenuTouchBFun(selfLayer, x, y)")
	local x, y = selfLayer:toLayerCoord(x, y)
	local quad2DTemp = selfLayer.data.quad2DFocus
	
	if selfLayer.data.quad2DPlay:hit2D(x, y) then
		selfLayer.data.quad2DFocus = selfLayer.data.quad2DPlay
	elseif selfLayer.data.quad2DQuit:hit2D(x, y) then
		selfLayer.data.quad2DFocus = selfLayer.data.quad2DQuit
	elseif selfLayer.data.quad2DAbout:hit2D(x, y) then
		selfLayer.data.quad2DFocus = selfLayer.data.quad2DAbout
	else
		selfLayer.data.quad2DFocus = nil
	end
	
	if quad2DTemp ~= selfLayer.data.quad2DFocus then
		if quad2DTemp ~= nil then
			quad2DTemp:setScale(1, 1, 1)
		end
		if selfLayer.data.quad2DFocus ~= nil then
			selfLayer.data.quad2DFocus:setScale(2, 2, 1)
		end
	end
	return true
end

local function MainMenuQuitTouchB(selfLayer, x, y)
	x, y = selfLayer:toLayerCoord(x, y)
	if selfLayer.data.textCancel:hit2D(x, y) then
		local sceneWM = share:director():current()
		sceneWM:pop()
		sceneWM:pop()
	elseif selfLayer.data.textQuit:hit2D(x, y) then
		share:scheduler():stop()
	end
	return true
end

local function MainMenuQuitLayout()
	local font = FontTTF:create("simsun.ttc", 80)
	local layerWM = Layer2D:create()
	layerWM:setViewArea(0, 0, 960, 640)
	layerWM:setTouchEnabled(true)
	local font = FontTTF:create("simsun.ttc", 80)
	local textMsg = LabelTTF:create("Are you sure Quit?", font)
	local textQuit = LabelTTF:create("Quit", font)
	local textCancel = LabelTTF:create("Cancel", font)
	
	textMsg:setPosition(480, 500)
	textMsg:setAlign(LabelTTF.ALIGN_H_CENTER, LabelTTF.ALIGN_V_CENTER)
	textMsg:setColor(Color.RED)
	textQuit:setPosition(200, 200)
	textQuit:setAlign(LabelTTF.ALIGN_H_CENTER, LabelTTF.ALIGN_V_CENTER)
	textQuit:setColor(Color.RED)
	textCancel:setPosition(760, 200)
	textCancel:setAlign(LabelTTF.ALIGN_H_CENTER, LabelTTF.ALIGN_V_CENTER)
	textCancel:setColor(Color.RED)
	
	layerWM:add(textMsg)
	layerWM:add(textQuit)
	layerWM:add(textCancel)
	
	layerWM.data = {}
	layerWM.data.textQuit = textQuit
	layerWM.data.textCancel = textCancel
	layerWM.data.onTouchBegin = MainMenuQuitTouchB
	
	return layerWM
end

local function MainMenuTouchEFun(selfLayer, x, y)
	print("run MainMenuTouchEFun(selfLayer, x, y)")
	local x, y = selfLayer:toLayerCoord(x, y)
	local quad2DTemp = selfLayer.data.quad2DFocus
	
	if selfLayer.data.quad2DPlay:hit2D(x, y) then
		selfLayer.data.quad2DFocus = selfLayer.data.quad2DPlay
	elseif selfLayer.data.quad2DQuit:hit2D(x, y) then
		selfLayer.data.quad2DFocus = selfLayer.data.quad2DQuit
	elseif selfLayer.data.quad2DAbout:hit2D(x, y) then
		selfLayer.data.quad2DFocus = selfLayer.data.quad2DAbout
	else
		selfLayer.data.quad2DFocus = nil
	end
	
	if quad2DTemp ~= nil then
		quad2DTemp:setScale(1, 1, 1)
	end
	
	if selfLayer.data.quad2DFocus ~= nil then
		quad2DTemp = selfLayer.data.quad2DFocus
		selfLayer.data.quad2DFocus:setScale(1, 1, 1)
		selfLayer.data.quad2DFocus = nil
		if quad2DTemp == selfLayer.data.quad2DQuit then
			local sceneWM = share:director():current()
			local layoutColorWM = ColorLayer:create(Color(20, 20, 20, 200))
			local layoutQuitWM = MainMenuQuitLayout()
			sceneWM:push(layoutColorWM)
			sceneWM:push(layoutQuitWM)
		elseif quad2DTemp == selfLayer.data.quad2DAbout then
			local directorWM = share:director()
			sceneWM = SceneAbout()
			directorWM:push();
			directorWM:run(sceneWM)
		elseif quad2DTemp == selfLayer.data.quad2DPlay then
			local directorWM = share:director()
			sceneWM = ScenePlay_New()
			directorWM:push()
			directorWM:run(sceneWM)
		end
		print("you have select a button")
	end
	return true
end

local function LayoutMainMenu() -- 创建 layout
	local layerWM = Layer2D:create()
	local spriteBK = Sprite2D:create("sprites/start.fst")
	local quad2DPlay = Quad2D:create("textures/play.png", 122, 43)
	local quad2DQuit = Quad2D:create("textures/quit.png", 122, 43)
	local quad2DAbout = Quad2D:create("textures/settings.png", 270, 46)
	
	layerWM:setViewArea(0, 0, 960, 640)
	quad2DPlay:setPosition(480, 240) -- the play button's position
	quad2DQuit:setPosition(480, 180) -- the quit button's position
	quad2DAbout:setPosition(480, 120) -- the setting button's position
	
	layerWM:add(spriteBK)
	layerWM:add(quad2DPlay)
	layerWM:add(quad2DQuit)
	layerWM:add(quad2DAbout)
	
	layerWM.data = {}
	layerWM.data.quad2DPlay = quad2DPlay
	layerWM.data.quad2DQuit = quad2DQuit
	layerWM.data.quad2DAbout = quad2DAbout
	layerWM.data.spriteBK = spriteBK
	
	layerWM:setTouchEnabled(false)
	
	layerWM.data.onEnter = MainMenuLayoutEnter
	layerWM.data.onUpdate = MainMenuLayoutUpdate
	layerWM.data.onTouchBegin = MainMenuTouchBFun
	layerWM.data.onTouchMove = MainMenuTouchBFun
	layerWM.data.onTouchEnd = MainMenuTouchEFun
	
	return layerWM
end

local function MainMenuSceneEnter(selfScene)
	selfScene:push(selfScene.data.layerWM)
	selfScene.data.layerWM.data.onEnter(selfScene.data.layerWM)
end

function SceneMainMenu() -- 创建 scene
	local sceneWM = Scene:create()
	local layerWM = LayoutMainMenu()
	
	sceneWM.data = {}
	sceneWM.data.layerWM = layerWM
	sceneWM.data.onEnter = MainMenuSceneEnter
	return sceneWM
end