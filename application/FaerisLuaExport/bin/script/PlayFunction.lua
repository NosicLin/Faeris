-- 方块集合的状态
local BLOCKUNIT_STATE_LIST = 
{
BLOCKUNIT_STATE_NOT = 0,
BLOCKUNIT_STATE_ENABEL = 1
}
-- 周围环境需要的变量
local BLOCKMOVE_MOMENT = 60 -- 60 -- 方块集合下落的间隔
local BLOCKUNIT_WH = 32 -- 方块是正方形，它的长宽
local BLOCK_RECT = Rect2D(-BLOCKUNIT_WH / 2, -BLOCKUNIT_WH / 2, BLOCKUNIT_WH, BLOCKUNIT_WH) -- 方块大小区域
local BLOCK_X_NUM = 10 -- 屏幕上水平和竖直的方块个数
local BLOCK_Y_NUM = 20 -- 屏幕上水平和竖直的方块个数
local BLOCKAREA_OFFSETX = 8 -- 堆方块区域相对于屏幕的偏移
local BLOCKAREA_OFFSETY = 102 -- 堆方块区域相对于屏幕的偏移
-- 滚动按钮的最小和最大x 和 y
local QUADSCROLL_MINX = 26
local QUADSCROLL_MAXX = 313
local QUADSCROLL_Y = 62
-- 变化方块集合的按钮的区域
local RECT_QUADCHANGE = Rect2D(344, 10, 120, 120)
-- 可以控制方块左右挪动的区域
local RECT_BLOCKMOVE = Rect2D(0, 0, 338, 94)
-- 方块资源路径表
local BLOCK_QUAD_RES = {
	{res = "textures/game/blockBlue.png"},
	{res = "textures/game/blockCyan.png"},
	{res = "textures/game/blockGreen.png"},
	{res = "textures/game/blockOrange.png"},
	{res = "textures/game/blockPurple.png"},
	{res = "textures/game/blockRed.png"},
	{res = "textures/game/blockYellow.png"},
}
-- 方块偏移表
local N3P3 = {indexX = -3, indexY = 3}
local N2P3 = {indexX = -2, indexY = 3}
local N1P3 = {indexX = -1, indexY = 3}
local P0P3 = {indexX = 0, indexY = 3}
local P1P3 = {indexX = 1, indexY = 3}
local P2P3 = {indexX = 2, indexY = 3}
local P3P3 = {indexX = 3, indexY = 3}

local N3P2 = {indexX = -3, indexY = 2}
local N2P2 = {indexX = -2, indexY = 2}
local N1P2 = {indexX = -1, indexY = 2}
local P0P2 = {indexX = 0, indexY = 2}
local P1P2 = {indexX = 1, indexY = 2}
local P2P2 = {indexX = 2, indexY = 2}
local P3P2 = {indexX = 3, indexY = 2}

local N3P1 = {indexX = -3, indexY = 1}
local N2P1 = {indexX = -2, indexY = 1}
local N1P1 = {indexX = -1, indexY = 1}
local P0P1 = {indexX = 0, indexY = 1}
local P1P1 = {indexX = 1, indexY = 1}
local P2P1 = {indexX = 2, indexY = 1}
local P3P1 = {indexX = 3, indexY = 1}

local N3P0 = {indexX = -3, indexY = 0}
local N2P0 = {indexX = -2, indexY = 0}
local N1P0 = {indexX = -1, indexY = 0}
local P0P0 = {indexX = 0, indexY = 0}
local P1P0 = {indexX = 1, indexY = 0}
local P2P0 = {indexX = 2, indexY = 0}
local P3P0 = {indexX = 3, indexY = 0}

local N3N1 = {indexX = -3, indexY = -1}
local N2N1 = {indexX = -2, indexY = -1}
local N1N1 = {indexX = -1, indexY = -1}
local P0N1 = {indexX = 0, indexY = -1}
local P1N1 = {indexX = 1, indexY = -1}
local P2N1 = {indexX = 2, indexY = -1}
local P3N1 = {indexX = 3, indexY = -1}

local N3N2 = {indexX = -3, indexY = -2}
local N2N2 = {indexX = -2, indexY = -2}
local N1N2 = {indexX = -1, indexY = -2}
local P0N2 = {indexX = 0, indexY = -2}
local P1N2 = {indexX = 1, indexY = -2}
local P2N2 = {indexX = 2, indexY = -2}
local P3N2 = {indexX = 3, indexY = -2}

local N3N3 = {indexX = -3, indexY = -3}
local N2N3 = {indexX = -2, indexY = -3}
local N1N3 = {indexX = -1, indexY = -3}
local P0N3 = {indexX = 0, indexY = -3}
local P1N3 = {indexX = 1, indexY = -3}
local P2N3 = {indexX = 2, indexY = -3}
local P3N3 = {indexX = 3, indexY = -3}
-- 方块形状表
local SHAPE_BLOCK_LIST = { -- 键即为type 变化的数量 单个方块的个数 变化表 (默认按逆时针方向旋转,纯记录形状，主要用于碰撞判断)
	{ changeNum = 4, blockNum = 4, changeList = {{P0N1, P0P0, P1P0, P2P0}, {P1P0, P0P0, P0P1, P0P2}, {P0P1, P0P0, N1P0, N2P0}, {N1P0, P0P0, P0N1, P0N2}} }, -- done 普通方块
	{ changeNum = 4, blockNum = 4, changeList = {{N2P0, N1P0, P0P0, P0N1}, {P1P0, P0P0, P0N1, P0N2}, {P0P1, P0P0, P1P0, P2P0}, {N1P0, P0P0, P0P1, P0P2}} }, -- done 普通方块
	{ changeNum = 1, blockNum = 4, changeList = {{P0P0, P1P0, P1P1, P0P1}} }, -- done 普通方块
	{ changeNum = 4, blockNum = 4, changeList = {{N1P0, P0P0, P1P0, P0P1}, {P0N1, P0P0, N1P0, P0P1}, {P0N1, N1P0, P0P0, P1P0}, {P0N1, P1P0, P0P0, P0P1}} }, -- done 普通方块
	{ changeNum = 2, blockNum = 4, changeList = {{P0N1, P0P0, N1P0, N1P1}, {N1P0, P0P0, P1P1, P0P1}} }, -- done 普通方块
	{ changeNum = 2, blockNum = 4, changeList = {{P0N1, P0P0, P1P0, P1P1}, {P1P0, P0P0, P0P1, N1P1}} }, -- done 普通方块
	{ changeNum = 2, blockNum = 4, changeList = {{N1P0, P0P0, P1P0, P2P0}, {P0N2, P0N1, P0P0, P0P1}} }, -- done 普通方块
	{ changeNum = 1, blockNum = 6, changeList = {{P0P0, N1P0, N2P2, P1P2, N1P1, P0P1}} }, -- done 炸弹
	{ changeNum = 4, blockNum = 4, changeList = {{P0N1, N1P1, P1P1, P0P0}, {N1N1, P0P0, P1P0, N1P1}, {N1N1, P1N1, P0P0, P0P1}, {P1N1, P0P0, N1P0, P1P1}} }, -- done 变化方块1
	{ changeNum = 4, blockNum = 5, changeList = {{N1N1, P0N1, P1N1, P0P0, P0P1}, {P1N1, N1P0, P0P0, P1P0, P1P1}, {P0N1, N1P1, P1P1, P0P0, P0P1}, {N1N1, P0P0, P1P0, N1P0, N1P1}} }, -- done
	{ changeNum = 4, blockNum = 5, changeList = {{N1N1, N1P0, N1P1, P0P1, P1P1}, {P1N1, P0N1, N1N1, N1P0, N1P1}, {N1N1, P0N1, P1N1, P1P0, P1P1}, {P1N1, P1P0, P1P1, P0P1, N1P1}} }, -- done 变化方块4
	{ changeNum = 4, blockNum = 5, changeList = {{N1N1, P1N1, P0P0, N1P0, P1P0}, {P1N1, P0N1, P0P0, P0P1, P1P1}, {N1P0, P0P0, P1P0, N1P1, P1P1}, {N1N1, P0N1, P0P0, P0P1, N1P1}} }, -- done 变化方块5
	{ changeNum = 4, blockNum = 5, changeList = {{N1N2, N1N1, N1P0, P0P0, P0P1}, {N1P1, P0P1, P0P0, P1P0, P2P0}, {N1P0, N1P1, P0P1, P0P2, P0P3}, {P0P0, N1P0, N1P1, N2P1, N3P1}} }, -- done 变化方块6
	{ changeNum = 2, blockNum = 5, changeList = {{P0N2, P0N1, P0P0, P0P1, P0P2}, {N2P0, N1P0, P0P0, P1P0, P2P0}} }, -- done
	{ changeNum = 2, blockNum = 6, changeList = {{N1P0, P0P0, P1P0, N1P1, P0P1, P1P1}, {P0P0, P1P0, P0P1, P1P1, P0P2, P1P2}} }, -- done
	{ changeNum = 1, blockNum = 5, changeList = {{N1P0, P0N1, P1P0, P0P0, P0P1}} }, -- done 十字架
	{ changeNum = 4, blockNum = 6, changeList = {{P0N1, N1P0, P1P0, P0P0, N1P1, P1P1}, {P1P0, P0N1, N1N1, P0P0, P0P1, N1P1}, {N1N1, P1N1, N1P0, P0P0, P1P0, P0P1}, {P1N1, P0N1, P0P0, N1P0, P0P1, P1P1}} }, -- done
	{ changeNum = 4, blockNum = 5, changeList = {{P1N1, P1P0, P0P0, P1P1, P0P1}, {P0P0, P1P0, P2P1, P1P1, P0P1}, {P0P0, P1P0, P1P1, P0P1, P0P2}, {N1P0, P0P0, P1P0, P0P1, P1P1}} }, -- done 变化方块11
	{ changeNum = 4, blockNum = 5, changeList = {{P0N1, P1N1, P0P0, P0P1, P0P2}, {N2P0, N1P0, P0P0, P1P0, P1P1}, {N1P1, P0P1, P0P0, P0N1, P0N2}, {N1N1, N1P0, P0P0, P1P0, P2P0}} }, -- done
	{ changeNum = 4, blockNum = 3, changeList = {{N1P0, P0P1, P1P0}, {P0N1, N1P0, P0P1}, {P0N1, N1P0, P1P0}, {P0N1, P1P0, P0P1}} }, -- done
	{ changeNum = 2, blockNum = 3, changeList = {{P0N1, P0P0, P0P1}, {N1P0, P0P0, P1P0}} },	
	{ changeNum = 1, blockNum = 1, changeList = {{P0P0}} },
	{ changeNum = 1, blockNum = 2, changeList = {{P0P0, P1P0}} },
	{ changeNum = 1, blockNum = 1, changeList = {{P1P0}} },
}

local function IndexXtoX(indexX) -- 可求出错误范围的坐标
	local x = BLOCKAREA_OFFSETX + indexX * BLOCKUNIT_WH + BLOCKUNIT_WH * 0.5
	return x
end

local function IndexYtoY(indexY) -- 可求出错误范围的坐标
	local y = BLOCKAREA_OFFSETY + indexY * BLOCKUNIT_WH + BLOCKUNIT_WH * 0.5
	return y
end

local function IndexToIndexX(index) -- 通过 BLOCK_X_NUM 求得正确范围的值
	local indexX = math.modf(index % BLOCK_X_NUM)
	return indexX
end

local function IndexToIndexY(index) -- 通过 BLOCK_X_NUM 求得正确范围的值
	local indexY = math.modf(index / BLOCK_X_NUM)
	return indexY
end

local function IndexXYToIndex(indexX, indexY) -- 不正确范围的 indexX 和 indexY 将转成 -100 的 index
	if indexX >= 0 and indexX < BLOCK_X_NUM and indexY >= 0 and indexY < BLOCK_Y_NUM then
		local index = indexY * BLOCK_X_NUM + indexX
		return index
	else
		return -15 -- 先弄成 -15 好观察错误
	end
end

local function XToIndexX(x)
	local indexX = math.modf((x - BLOCKAREA_OFFSETX) / BLOCKUNIT_WH)
	
	if indexX < 0 then
		indexX = indexX - 1
	end
	return indexX
end

local function YToIndexY(y)
	local indexY = math.modf((y - BLOCKAREA_OFFSETY) / BLOCKUNIT_WH)
	
	if indexY < 0 then
		indexY = indexY - 1
	end
	return indexY
end

local function CreatePlayLayerStruct(selfLayer)
	if selfLayer.data == nil then
		selfLayer.data = {}
	end
	
	selfLayer.blockMoveMoment = BLOCKMOVE_MOMENT / 2
	selfLayer.quadScroll = nil
	selfLayer.rectQuadChange = RECT_QUADCHANGE
	selfLayer.rectBlockMove = RECT_BLOCKMOVE
	selfLayer.targetIndexX = BLOCK_X_NUM / 2
	selfLayer.targetIndexY = BLOCK_Y_NUM + 1
	selfLayer.pressMoveSign = false
	selfLayer.pressBlockUnitSign = false
	selfLayer.chechMapRaseSign = false
	selfLayer.chechMapMoveSign = false
	selfLayer.nextBlockUnit = nil
	selfLayer.blockUnit = nil
	selfLayer.blockMap = nil
end

local function BlockMapData_Create()
	local blockMap = {}
	for i = 0, BLOCK_X_NUM * BLOCK_Y_NUM - 1 do
		blockMap[i] = {}
		blockMap[i].index = i
		blockMap[i].quadRes = nil
	end
	return blockMap
end

local function BlockMapData_Delete(selfLayer, blockMap)
	for i = 0, BLOCK_X_NUM * BLOCK_Y_NUM - 1 do
		blockMap[i].quadRes:detach()
		blockMap[i].quadRes = nil
	end
end

local function BlockUnitData_Create()
	local blockUnit = {}
	blockUnit.state = BLOCKUNIT_STATE_LIST.BLOCKUNIT_STATE_NOT
	blockUnit.indexX = 0
	blockUnit.indexY = 0
	blockUnit.shapeType = 1 -- 从1开始
	blockUnit.changeNum = 1 -- 从1开始
	local shapeType = blockUnit.shapeType
	local changeNum = blockUnit.changeNum
	blockUnit.blockNum = SHAPE_BLOCK_LIST[blockUnit.shapeType].blockNum
	local blockXYOffset = SHAPE_BLOCK_LIST[shapeType].changeList[changeNum]
	blockUnit.quadEntitys = {}
	for i = 1, blockUnit.blockNum do
		blockUnit.quadEntitys[i] = {}
		blockUnit.quadEntitys[i].indexX = blockUnit.indexX + blockXYOffset[i].indexX
		blockUnit.quadEntitys[i].indexY = blockUnit.indexY + blockXYOffset[i].indexY
		blockUnit.quadEntitys[i].quadRes = nil 
	end
	return blockUnit
end

local function BlockUnitData_DeleteRes(blockUnit)
	for i = 1, blockUnit.blockNum do
		if blockUnit.quadEntitys[i].quadRes ~= nil then
			blockUnit.quadEntitys[i].quadRes:detach()
			blockUnit.quadEntitys[i].quadRes = nil
		end
	end
end

local function BlockUnitData_Set(blockUnit, indexX, indexY, shapeType, changeNum) -- 这个函数会删除资源
	-- print("run function BlockUnitData_Set(blockUnit, indexX, indexY, shapeType, changeNum)")
	local changeNum = ((changeNum - 1) % SHAPE_BLOCK_LIST[shapeType].changeNum) + 1
	BlockUnitData_DeleteRes(blockUnit) -- 删除资源
	blockUnit.indexX = indexX
	blockUnit.indexY = indexY
	blockUnit.shapeType = shapeType -- 从1开始
	blockUnit.changeNum = changeNum -- 从1开始
	local shapeType = blockUnit.shapeType
	local changeNum = blockUnit.changeNum
	blockUnit.blockNum = SHAPE_BLOCK_LIST[blockUnit.shapeType].blockNum
	local blockXYOffset = SHAPE_BLOCK_LIST[shapeType].changeList[changeNum]
	blockUnit.quadEntitys = {}
	for i = 1, blockUnit.blockNum do
		blockUnit.quadEntitys[i] = {}
		blockUnit.quadEntitys[i].indexX = blockUnit.indexX + blockXYOffset[i].indexX
		blockUnit.quadEntitys[i].indexY = blockUnit.indexY + blockXYOffset[i].indexY
		blockUnit.quadEntitys[i].quadRes = nil 
	end
end

local function BlockUnitData_StateSet(blockUnit, state)
	blockUnit.state = state
end

local function BlockUnitData_AddRes(selfLayer, blockUnit, resPath)
	local shapeType = blockUnit.shapeType
	local changeNum = blockUnit.changeNum
	local blockXYOffset = SHAPE_BLOCK_LIST[shapeType].changeList[changeNum]
	for i = 1, blockUnit.blockNum do
		local indexX = blockUnit.quadEntitys[i].indexX
		local indexY = blockUnit.quadEntitys[i].indexY
		local quadRes = Quad2D:create(resPath, BLOCK_RECT)
		blockUnit.quadEntitys[i].quadRes = quadRes
		quadRes:setPosition(IndexXtoX(indexX), IndexYtoY(indexY))
		selfLayer:add(quadRes)
	end
end

local function BlockUnitData_Delete(blockUnit)
	BlockUnitData_DeleteRes(blockUnit)
	-- BlockUnitData_StateSet(BLOCKUNIT_STATE_LIST.BLOCKUNIT_STATE_NOT)
end

local function BlockUnitDataToMap_MoveRes(blockMap, blockUnit)
	local quadEntitys = blockUnit.quadEntitys
	for i = 1, blockUnit.blockNum do
		local index = IndexXYToIndex(quadEntitys[i].indexX, quadEntitys[i].indexY)
		-- print("输出index为 " .. quadEntitys[i].indexX .. " XXX " .. quadEntitys[i].indexY .. " XXX " .. index)
		if index >= 0 then
			if quadEntitys[i].quadRes ~= nil then
				if blockMap[index].quadRes ~=nil then
					blockMap[index].quadRes:detach()
					blockMap[index].quadRes = nil
				end
				blockMap[index].quadRes = quadEntitys[i].quadRes
				quadEntitys[i].quadRes = nil
			end
		else
			-- 方块不在合法范围内
		end
	end
end

local function IsHitMap(blockMap, indexX, indexY) -- 单纯地判断是否碰到 blockMap 中的方块
	local index = IndexXYToIndex(indexX, indexY)
	if index < 0 or index > BLOCK_X_NUM * BLOCK_Y_NUM - 1 then
		return false
	end
	if blockMap[index].quadRes == nil then
		return false
	end
	return true
end

local function IsHitLeft(indexX, indexY)
	if indexX < 0 then
		return true
	end
	return false
end

local function IsHitRight(indexX, indexY)
	if indexX > BLOCK_X_NUM - 1 then
		return true
	end
	return false
end

local function IsHitUp(indexX, indexY)
	if indexY > BLOCK_Y_NUM - 1 then
		return true
	end
	return false
end

local function IsHitDown(indexX, indexY)
	if indexY < 0 then
		return true
	end
	return false
end

local function BlockUnit_GetCurChangeNum(blockUnit)
	return blockUnit.changeNum
end

local function BlockUnit_GetChangeNum(blockUnit)
	return SHAPE_BLOCK_LIST[blockUnit.shapeType].changeNum
end

local function BlockUnit_GetShapeType(blockUnit)
	return blockUnit.shapeType
end

local function SetQuadScrollPostion(quadScroll, x)
	if x < QUADSCROLL_MINX then
		x = QUADSCROLL_MINX
	elseif x > QUADSCROLL_MAXX then
		x = QUADSCROLL_MAXX
	end
	quadScroll:setPosition(x, QUADSCROLL_Y)
end

local function PointIsInRect(x, y, rect)
	if x >= rect.x and x <= rect.x + rect.width and y >= rect.y and y <= rect.y + rect.height then
		return true
	end
	return false
end

-- -------------------------- 扩展函数 --------------------------------------

local function BlockUnitData_DataCreate(indexX, indexY, shapeType, changeNum) -- 不创建资源
	local blockUnit = BlockUnitData_Create()
	BlockUnitData_Set(blockUnit, indexX, indexY, shapeType, changeNum) -- 这个函数会删除资源
	return blockUnit
end

local function BlockUnitData_DataSet(blockUnit, indexX, indexY, changeNum) -- 因为没有 shapeType 所以不涉及资源的创建和删除
	-- print("run function BlockUnitData_DataSet(blockUnit, indexX, indexY, changeNum)")
	local changeNum = ((changeNum - 1) % SHAPE_BLOCK_LIST[blockUnit.shapeType].changeNum) + 1
	blockUnit.indexX = indexX
	blockUnit.indexY = indexY
	blockUnit.changeNum = changeNum -- 从 1 开始
	local shapeType = blockUnit.shapeType
	local changeNum = blockUnit.changeNum
	local blockXYOffset = SHAPE_BLOCK_LIST[shapeType].changeList[changeNum]
	for i = 1, blockUnit.blockNum do
		local indexX = blockUnit.indexX + blockXYOffset[i].indexX
		local indexY = blockUnit.indexY + blockXYOffset[i].indexY
		blockUnit.quadEntitys[i].indexX = indexX
		blockUnit.quadEntitys[i].indexY = indexY
		if blockUnit.quadEntitys[i].quadRes ~= nil then
			local quadRes = blockUnit.quadEntitys[i].quadRes
			quadRes:setPosition(IndexXtoX(indexX), IndexYtoY(indexY))
		end
	end
end 

local function BlockUnitIsHitMap(blockUnit, blockMap) -- 方块集合是否撞到Map， blockUnit 只看坐标而 blockMap 须看资源来判断碰撞
	for i = 1, blockUnit.blockNum do
		local indexX = blockUnit.quadEntitys[i].indexX
		local indexY = blockUnit.quadEntitys[i].indexY
		if IsHitMap(blockMap, indexX, indexY) then
			return true
		end
	end
	return false
end

local function BlockUnitIsHitLeft(blockUnit) -- 方块集合是否撞到左边墙壁
	for i = 1, blockUnit.blockNum do
		local indexX = blockUnit.quadEntitys[i].indexX
		local indexY = blockUnit.quadEntitys[i].indexY
		if IsHitLeft(indexX, indexY) then
			return true
		end
	end
	return false
end

local function BlockUnitIsHitRight(blockUnit) -- 方块集合是否撞到右边墙壁
	for i = 1, blockUnit.blockNum do
		local indexX = blockUnit.quadEntitys[i].indexX
		local indexY = blockUnit.quadEntitys[i].indexY
		if IsHitRight(indexX, indexY) then
			return true
		end
	end
	return false
end

local function BlockUnitIsHitUp(blockUnit) -- 方块集合是否撞到上边墙壁
	for i = 1, blockUnit.blockNum do
		local indexX = blockUnit.quadEntitys[i].indexX
		local indexY = blockUnit.quadEntitys[i].indexY
		if IsHitUp(indexX, indexY) then
			return true
		end
	end
	return false
end

local function BlockUnitIsHitDown(blockUnit) -- 方块集合是否撞到下边墙壁
	for i = 1, blockUnit.blockNum do
		local indexX = blockUnit.quadEntitys[i].indexX
		local indexY = blockUnit.quadEntitys[i].indexY
		if IsHitDown(indexX, indexY) then
			return true
		end
	end
	return false
end

local function GetScrollIndexX(quadScroll)
	local indexX = XToIndexX(quadScroll:getPositionX() - BLOCKAREA_OFFSETX)
	return indexX
end

local function BlockUnitIsHited(blockUnit, x, y) -- 不管这个方块集合有没有quad都计算
	for i = 1, blockUnit.blockNum do
		local indexX = blockUnit.quadEntitys[i].indexX
		local indexY = blockUnit.quadEntitys[i].indexY
		if indexX == XToIndexX(x) and indexY == YToIndexY(y) then
			return true
		end
	end
	return false
end

local function BlockMapIsLineEmpty(blockMap, indexY)
	if indexY > BLOCK_Y_NUM - 1 or indexY < 0 then
		return true
	end
	for i = 0, BLOCK_X_NUM - 1 do
		local index = IndexXYToIndex(i, indexY)
		if blockMap[index].quadRes ~= nil then
			return false
		end
	end
	return true
end

local function BlockMapIsLineFull(blockMap, indexY)
	if indexY > BLOCK_Y_NUM - 1 or indexY < 0 then
		return false
	end
	for i = 0, BLOCK_X_NUM - 1 do
		local index = IndexXYToIndex(i, indexY)
		if blockMap[index].quadRes == nil then
			-- print("不是满的")
			return false
		end
	end
	-- print("是满的")
	return true
end

local function BlockMapDeleteLine(blockMap, indexY)
	if indexY < 0 or indexY > BLOCK_Y_NUM - 1 then
		return
	end
	for i = 0, BLOCK_X_NUM - 1 do
		local targetIndex = IndexXYToIndex(i, indexY)
		if blockMap[targetIndex].quadRes ~= nil then
			blockMap[targetIndex].quadRes:detach()
			blockMap[targetIndex].quadRes = nil
		end
	end
end

local function BlockMapMoveLineToLine(blockMap, targetIndexY, srcIndexY) -- 单纯移动，强制覆盖
	-- 满足这三个条件直接退出
	if targetIndexY == srcIndexY then
		return
	end
	if targetIndexY < 0 or targetIndexY > BLOCK_Y_NUM - 1 then
		return
	end
	if srcIndexY < 0 or srcIndexY > BLOCK_Y_NUM - 1 then
		return
	end
	BlockMapDeleteLine(blockMap, targetIndexY)
	for i = 0, BLOCK_X_NUM - 1 do
		local targetIndex = IndexXYToIndex(i, targetIndexY)
		local srcIndex = IndexXYToIndex(i, srcIndexY)
		blockMap[targetIndex].quadRes = blockMap[srcIndex].quadRes
		blockMap[srcIndex].quadRes = nil
		if blockMap[targetIndex].quadRes ~= nil then
			local indexX = IndexToIndexX(targetIndex)
			local indexY = IndexToIndexY(targetIndex)
			local x = IndexXtoX(indexX)
			local y = IndexYtoY(indexY)
			blockMap[targetIndex].quadRes:setPosition(x, y)
		end
	end
	-- 尽量分离开，这样写没体现出模块性
-- 	for i = 0, i < BLOCK_X_NUM do
-- 		local targetIndex = IndexXYToIndex(i, targetIndexY)
-- 		if blockMap[targetIndex].quadRes ~= nil then
-- 			blockMap[targetIndex].quadRes:detach()
-- 			blockMap[targetIndex].quadRes = nil
-- 		end
-- 		local srcIndex = IndexXYToIndex(i, srcIndexY)
-- 		blockMap[targetIndex].quadRes = blockMap[srcIndex].quadRes
-- 		blockMap[srcIndex].quadRes = nil
-- 		if blockMap[targetIndex].quadRes ~= nil then
-- 			local indexX = IndexToIndexX(targetIndex)
-- 			local indexY = IndexToIndexY(targetIndex)
-- 			local x = IndexXtoX(indexX)
-- 			local y = IndexXtoY(indexY)
-- 			blockMap[targetIndex].quadRes:setPosition(x, y)
-- 		end
-- 	end
end

-- ---------------------------- 游戏逻辑函数 ----------------------------------

local function UIRes_Load(selfLayer)
	local quadScroll = Quad2D:create("textures/game/valueHScrollBar.png")
	quadScroll:setPosition(IndexXtoX(BLOCK_X_NUM / 2), QUADSCROLL_Y)
	selfLayer:add(quadScroll)
	selfLayer.quadScroll = quadScroll
end

local function LayerPlay_GameMainLogic(selfLayer, dt)
	if selfLayer.nextBlockUnit == nil then -- 下一个方块为空说明游戏刚开始
		selfLayer.nextBlockUnit = BlockUnitData_Create()
		local shapeType = math.random(1, #SHAPE_BLOCK_LIST)
		BlockUnitData_Set(selfLayer.nextBlockUnit, 12, 17, shapeType, math.random(1, SHAPE_BLOCK_LIST[shapeType].changeNum))
		BlockUnitData_AddRes(selfLayer, selfLayer.nextBlockUnit, BLOCK_QUAD_RES[math.random(1, #BLOCK_QUAD_RES)].res)
		BlockUnitData_Delete(selfLayer.blockUnit)
		selfLayer.targetIndexY = BLOCK_Y_NUM
		selfLayer.chechMapRaseSign = true
		local shapeType = math.random(1, #SHAPE_BLOCK_LIST)
		BlockUnitData_Set(selfLayer.blockUnit, BLOCK_X_NUM / 2, selfLayer.targetIndexY, shapeType, math.random(1, SHAPE_BLOCK_LIST[shapeType].changeNum))
		BlockUnitData_AddRes(selfLayer, selfLayer.blockUnit, BLOCK_QUAD_RES[math.random(1, #BLOCK_QUAD_RES)].res)
	end
	
	if selfLayer.blockMoveMoment <= 0 then
		selfLayer.blockMoveMoment = BLOCKMOVE_MOMENT -- 固定的
		-- 开始做一些动作
		-- 先判断能不能动再动
		-- function BlockUnitData_DataCreate(indexX, indexY, shapeType, changeNum)
		local blockUnit = BlockUnitData_DataCreate(selfLayer.blockUnit.indexX, selfLayer.blockUnit.indexY - 1, BlockUnit_GetShapeType(selfLayer.blockUnit), BlockUnit_GetCurChangeNum(selfLayer.blockUnit))
		local bSign = false
		if BlockUnitIsHitMap(blockUnit, selfLayer.blockMap) then
			bSign = true -- 这里还要判断是撞到下面的方块还是撞到旁边的方块,貌似在横向移动中才要判断
		elseif BlockUnitIsHitDown(blockUnit) then
			bSign = true
		end
		-- 若撞到则固定并产生新的方块集合，若不撞到则下挪
		if bSign then
			-- function BlockUnitDataToMap_MoveRes(blockMap, blockUnit)
			BlockUnitDataToMap_MoveRes(selfLayer.blockMap, selfLayer.blockUnit)
			-- 产生新的方块 -- 顺便还要重置一些数据
			BlockUnitData_Delete(selfLayer.blockUnit) -- 这句话待考虑要不要
			selfLayer.blockUnit = selfLayer.nextBlockUnit
			selfLayer.targetIndexY = BLOCK_Y_NUM
			selfLayer.chechMapRaseSign = true
			BlockUnitData_DataSet(selfLayer.blockUnit, BLOCK_X_NUM / 2, selfLayer.targetIndexY,  BlockUnit_GetCurChangeNum(selfLayer.blockUnit))
			-- 产生下一个方块
			selfLayer.nextBlockUnit = BlockUnitData_Create()
			local shapeType = math.random(1, #SHAPE_BLOCK_LIST)
			BlockUnitData_Set(selfLayer.nextBlockUnit, 12, 17, shapeType, math.random(1, SHAPE_BLOCK_LIST[shapeType].changeNum))
			BlockUnitData_AddRes(selfLayer, selfLayer.nextBlockUnit, BLOCK_QUAD_RES[math.random(1, #BLOCK_QUAD_RES)].res)
		else
			-- function BlockUnitData_DataSet(blockUnit, indexX, indexY, changeNum)
			BlockUnitData_DataSet(selfLayer.blockUnit, selfLayer.blockUnit.indexX, selfLayer.blockUnit.indexY - 1, BlockUnit_GetCurChangeNum(selfLayer.blockUnit))
		end
	else
		selfLayer.blockMoveMoment = selfLayer.blockMoveMoment - 1 -- 固定的
		-- 横向挪动
		if selfLayer.targetIndexX > selfLayer.blockUnit.indexX then
			-- 开始做一些动作
			-- 先判断能不能动再动
			-- BlockUnitData_DataCreate(indexX, indexY, shapeType, changeNum)
			local blockUnit = BlockUnitData_DataCreate(selfLayer.blockUnit.indexX + 1, selfLayer.blockUnit.indexY, BlockUnit_GetShapeType(selfLayer.blockUnit), BlockUnit_GetCurChangeNum(selfLayer.blockUnit))
			local bSign = false
			if BlockUnitIsHitMap(blockUnit, selfLayer.blockMap) then
				bSign = true
			elseif BlockUnitIsHitRight(blockUnit) then
				bSign = true
			elseif BlockUnitIsHitDown(blockUnit) then
				bSign = true
			end
			if not bSign then
				BlockUnitData_DataSet(selfLayer.blockUnit, selfLayer.blockUnit.indexX + 1, selfLayer.blockUnit.indexY, BlockUnit_GetCurChangeNum(selfLayer.blockUnit))
			end
		elseif selfLayer.targetIndexX < selfLayer.blockUnit.indexX then
			-- 开始做一些动作
			-- 先判断能不能动再动
			-- BlockUnitData_DataCreate(indexX, indexY, shapeType, changeNum)
			local blockUnit = BlockUnitData_DataCreate(selfLayer.blockUnit.indexX - 1, selfLayer.blockUnit.indexY, BlockUnit_GetShapeType(selfLayer.blockUnit), BlockUnit_GetCurChangeNum(selfLayer.blockUnit))
			local bSign = false
			if BlockUnitIsHitMap(blockUnit, selfLayer.blockMap) then
				bSign = true
			elseif BlockUnitIsHitLeft(blockUnit) then
				bSign = true
			elseif BlockUnitIsHitDown(blockUnit) then
				bSign = true
			end
			if not bSign then
				BlockUnitData_DataSet(selfLayer.blockUnit, selfLayer.blockUnit.indexX - 1, selfLayer.blockUnit.indexY, BlockUnit_GetCurChangeNum(selfLayer.blockUnit))
			end
		end
		-- 纵向移动
		if selfLayer.targetIndexY < selfLayer.blockUnit.indexY then
			if selfLayer.blockMoveMoment > 2 then -- 给玩家更多横向移动的机会
				selfLayer.blockMoveMoment = 2
			end
		end
		-- 由于现在还没有限定状态来控制游戏 消方块的过程暂时放到这里
		local blockMap = selfLayer.blockMap
		if selfLayer.chechMapRaseSign then
			for i = 0, BLOCK_Y_NUM - 1 do
				if BlockMapIsLineFull(blockMap, i) then
					print("满一行")
					BlockMapDeleteLine(blockMap, i)
					selfLayer.chechMapMoveSign = true
				end
			end
			selfLayer.chechMapRaseSign = false
		end
		if selfLayer.chechMapMoveSign then
			local bSign = true
			for i = 0, BLOCK_Y_NUM - 1 do
				if BlockMapIsLineEmpty(blockMap, i) then
					for j = i, BLOCK_Y_NUM - 2 do
						BlockMapMoveLineToLine(blockMap, j, j + 1)
						if not BlockMapIsLineEmpty(blockMap, j) then
							bSign = false
						end
					end
					break
				end
			end
			if bSign then -- 说明检查完了
				print("检查完了")
				selfLayer.chechMapMoveSign = false
			end
		end
	end
end

local function LayerPlay_OnUpdate(selfLayer, dt)
	selfLayer:update(dt)
	LayerPlay_GameMainLogic(selfLayer, dt)
end

local function TestFunction(selfLayer, x, y) -- 0 到 1 的坐标
	if y > 0.96 then 
		g_testNumA = g_testNumA + 1
		if g_testNumA > #SHAPE_BLOCK_LIST then
			g_testNumA = 1
		end
		BlockUnitData_Set(selfLayer.blockUnit, selfLayer.blockUnit.indexX, selfLayer.blockUnit.indexY, g_testNumA, g_testNumB)
		BlockUnitData_AddRes(selfLayer, selfLayer.blockUnit, BLOCK_QUAD_RES[math.random(1, #BLOCK_QUAD_RES)].res)
	end
end

local function RotateBlockUnit_OnTouchBegin(selfLayer, x, y) -- x, y 为图层坐标
	-- 判断能不能旋转 -- 只能在X轴上进行改变
 	local bSign = false
	local offsetX = 0
	-- 构造一个原地旋转的方块
 	local blockUnit = BlockUnitData_DataCreate(selfLayer.blockUnit.indexX, selfLayer.blockUnit.indexY, BlockUnit_GetShapeType(selfLayer.blockUnit), BlockUnit_GetCurChangeNum(selfLayer.blockUnit) + 1) 
	if BlockUnitIsHitMap(blockUnit, selfLayer.blockMap) or BlockUnitIsHitLeft(blockUnit, selfLayer.blockMap) or BlockUnitIsHitRight(blockUnit, selfLayer.blockMap) or BlockUnitIsHitDown(blockUnit, selfLayer.blockMap) then
		bSign = true
	end
	-- 若撞到了再右挪 3 个单位来比较
	if bSign then
		bSign = false
		for i = 1, 3, 1 do
			local blockUnit = BlockUnitData_DataCreate(selfLayer.blockUnit.indexX + i, selfLayer.blockUnit.indexY, BlockUnit_GetShapeType(selfLayer.blockUnit), BlockUnit_GetCurChangeNum(selfLayer.blockUnit) + 1)
			if BlockUnitIsHitMap(blockUnit, selfLayer.blockMap) or BlockUnitIsHitLeft(blockUnit, selfLayer.blockMap) or BlockUnitIsHitRight(blockUnit, selfLayer.blockMap) or BlockUnitIsHitDown(blockUnit, selfLayer.blockMap) then
				bSign = true
			else
				bSign = false
				offsetX = i
				break
			end
		end
	end
	-- 若撞到了再左挪 3 个单位来比较
	if bSign then
		bSign = false
		for i = -1, -3, -1 do
			local blockUnit = BlockUnitData_DataCreate(selfLayer.blockUnit.indexX + i, selfLayer.blockUnit.indexY, BlockUnit_GetShapeType(selfLayer.blockUnit), BlockUnit_GetCurChangeNum(selfLayer.blockUnit) + 1)
			if BlockUnitIsHitMap(blockUnit, selfLayer.blockMap) or BlockUnitIsHitLeft(blockUnit, selfLayer.blockMap) or BlockUnitIsHitRight(blockUnit, selfLayer.blockMap) or BlockUnitIsHitDown(blockUnit, selfLayer.blockMap) then
				bSign = true
			else
				bSign = false
				offsetX = i
				break
			end
		end
	end
	if not bSign then -- 没撞上才能改变
		BlockUnitData_DataSet(selfLayer.blockUnit, selfLayer.blockUnit.indexX + offsetX, selfLayer.blockUnit.indexY, BlockUnit_GetCurChangeNum(selfLayer.blockUnit) + 1)
	end
end

local function ChangeBlockUnitX_OnTouchBegin(selfLayer, x, y) -- x, y 为图层坐标
	SetQuadScrollPostion(selfLayer.quadScroll, x)
 	selfLayer.targetIndexX = GetScrollIndexX(selfLayer.quadScroll)
 	selfLayer.pressedButton = true
end

local function LayerPlay_OnTouchBegin(selfLayer, x, y)  -- x, y 为 0 到 1
	-- 一个调试功能
	TestFunction(selfLayer, x, y)
	-- 转换成图层坐
 	x, y = selfLayer:toLayerCoord(x, y)
 	print("indexX = " .. XToIndexX(x) .. " indexY = " .. YToIndexY(y))
 	-- 判断是否点中变化方块的按钮
 	if PointIsInRect(x, y, selfLayer.rectQuadChange) then
 		RotateBlockUnit_OnTouchBegin(selfLayer, x, y) -- 到时候还要看是不是炸弹、变化方块
 	elseif PointIsInRect(x, y, selfLayer.rectBlockMove) then -- 获得 targetIndexX 先判断在不在方块区域内
 		ChangeBlockUnitX_OnTouchBegin(selfLayer, x, y)
 	elseif BlockUnitIsHited(selfLayer.blockUnit, x, y) then -- 是否点中了运动中的方块
 		selfLayer.pressBlockUnitSign = true
 	end
	return false
end

local function LayerPlay_OnTouchMove(selfLayer, x, y)
	x, y = selfLayer:toLayerCoord(x, y)
	-- 获得 targetIndexX 先判断在不在方块区域内
 	local rectBlockMove = selfLayer.rectBlockMove
 	if selfLayer.pressedButton then -- 由于在模拟器上鼠标移出屏幕不会有 onTouchEnd() 但是手机上有，所以模拟器上出这个bug不用管
 		SetQuadScrollPostion(selfLayer.quadScroll, x)
 		selfLayer.targetIndexX = GetScrollIndexX(selfLayer.quadScroll)
 	end
	return false
end

local function LayerPlay_OnTouchEnd(selfLayer, x, y)
	x, y = selfLayer:toLayerCoord(x, y)
	selfLayer.pressedButton = false -- 基本固定
	if selfLayer.pressBlockUnitSign then
		selfLayer.pressBlockUnitSign = false -- 基本固定
		if BlockUnitIsHited(selfLayer.blockUnit, x, y) then
			selfLayer.targetIndexY = 0
		end
	end
	
	-- print("indexY = " .. YToIndexY(y))
	return false
end

-- ------------------- LayerPlay_Create() ------------------------------------------

g_testNumA = 1
g_testNumB = 1
g_testNumC = 0

function LayerPlay_Create()
	-- init
	local layerPlay = Layer2D:create()
	layerPlay:setSortMode(Layer2D.SORT_ORDER_Z)
	layerPlay:setViewArea(0, 0, 480, 800)
	layerPlay:setTouchEnabled(true)
	layerPlay.data = {}
	-- end init
	CreatePlayLayerStruct(layerPlay)
	UIRes_Load(layerPlay)
	layerPlay.blockMap = BlockMapData_Create()
	
	-- 产生一个方块
	layerPlay.blockUnit = BlockUnitData_Create()
	-- local shapeType = math.random(1, #SHAPE_BLOCK_LIST)
	-- BlockUnitData_Set(layerPlay.blockUnit, 5, 20, shapeType, math.random(1, SHAPE_BLOCK_LIST[shapeType].changeNum))
	-- BlockUnitData_AddRes(layerPlay, layerPlay.blockUnit, BLOCK_QUAD_RES[math.random(1, #BLOCK_QUAD_RES)].res)
	
	-- 重置一些全局变量
	g_testNumA = 1
	g_testNumB = 1
	g_testNumC = 0
	
	layerPlay.onUpdate = LayerPlay_OnUpdate
	layerPlay.onTouchBegin = LayerPlay_OnTouchBegin
	layerPlay.onTouchMove = LayerPlay_OnTouchMove
	layerPlay.onTouchEnd = LayerPlay_OnTouchEnd
	
	return layerPlay
end