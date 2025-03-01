#include "RewardBlock.h"

// 构造函数：初始化窗口尺寸和奖励方块
RewardBlock::RewardBlock(int windowWidth, int windowHeight)
    : windowWidth(windowWidth), windowHeight(windowHeight), active(false) {
    reset();  // 初始化奖励方块的位置
}

// 重置奖励方块的位置
void RewardBlock::reset() {
    int x = QRandomGenerator::global()->bounded(windowWidth - 30);  // 随机x坐标
    int y = QRandomGenerator::global()->bounded(600, windowHeight - 100);  // 随机y坐标（地面以上）
    rect = QRect(x, y, 30, 30);  // 奖励方块尺寸 30x30
    active = true;  // 激活奖励方块
}

// 绘制奖励方块
void RewardBlock::draw(QPainter *painter) {
    if (active) {
        painter->setBrush(Qt::green);  // 绿色方块
        painter->drawRect(rect);
    }
}

// 检测与玩家的碰撞
bool RewardBlock::checkCollision(const QRect &playerRect) {
    if (active && playerRect.intersects(rect)) {
        active = false;  // 碰撞后奖励方块消失
        return true;
    }
    return false;
}

// 获取奖励方块的矩形区域
QRect RewardBlock::getRect() const {
    return rect;
}

// 判断奖励方块是否激活
bool RewardBlock::isActive() const {
    return active;
}
