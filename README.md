# Gwent
A game project from the GUI programming course, mimicing the card game Gwent, developed by Qt in summer, 2017.

## 1. 各程序模块间逻辑关系
  1. `MainWindow`类掌管首页接口，可引领至`DeckControl`、`GameControl`类对象或结束程序。
  2. `DeckControl`类管理组牌接口与背后算法，主要成员是`BattleField`、`Card`、与`Deck`。
  3. `BattleField`内含四个`Field`，即四行出牌的地方，远中近战与效果牌。每一排都由一个`Field`管理，将`Card`对象添加到`Field`中，则`Field`可处理`Card`的位置与显示效果。
  4. `Card`是所有卡牌的基类。另外有派生类`Card001`, `Card002`, ....`Card027`代表27张不同卡牌，用`Card`指针可创建或访问27种不同的卡牌，且创建时已赋有对应的能力、图形、属性。
  5. `Deck`用于纪录一套牌的成分。当中用`MultiMap`纪录卡牌序号(如1、1、2、3、4、4…)，以及该张在组牌时所放在的排(`Field`、`lane`)。
  6. `GameControl`类管理游戏接口与背后算法，主要是两个`Player`(`player`和`opponent`)之间的交互关系，另有内含六个`Field`的`BattleField`，代表六行出牌的地方，可侦测使用者点击的区块。
  7. `Player`类管理游戏进行中，单一玩家的状态与卡牌信息。其中拥有多个`Field`，包括手牌、墓地、牌堆、战场，都各是一个`Field`，其中战场`battleField`底下又再有三个`Field`分别代表远中近战。图形上卡牌变换位置，其背后就是将卡牌在不同`Field`间移出移入的操作。`Player`另有接口函数可处理生成牌堆、随机抽牌、调度、清理战场等功能。
  8. `Account`类的对象`account`存在于全局，用来记录至多五组在`DeckControl`中的组的牌组，并提供给`GameControl`进行游戏开局。同时`Account`也会在运行开始时读取本地文件`account.txt`来载入上次游戏所保存的牌组，也会在退出`DeckControl`时将最新的牌组信息再次存到`account.txt`中，已供下次使用。

## 2. 程序运行主要流程
此程序是一层一层深入函数的概念，往往利用`QEventLoop`将函数暂停而不退出，以在当下函数位置等待用户的操作信号。只有当用户给入信号，才会前进或后退(往下层函数深入或向上层函数退出)。
![Alt text](./ProcessLogic.jpg?raw=true "Title")

## 3. 游戏操作方法
  1. 首页
     1. AI按钮无功能
     2. Deck进入牌组选单
     3. Game进入游戏选单
     4. Exit退出程序
  2. 牌组选单
     1. Deck1~Deck5进入牌组编辑
     2. Go back 以退回
     3. 选取下方卡牌再选取放置位置即可添加
     4. 选取上方牌可直接撤销
     5. 领袖牌只需单击一次即可放入，点击其他领袖牌以取代当前领袖牌
     6. 未选取领袖牌或未满25张禁止退出编辑
  3. 游戏选单
     1. Deck1~Deck5选择牌组游戏
     2. Back 以退回
     3. 选取不合格牌组无法开始游戏
     4. 双方都需由使用者操作
     5. 先由我方开始调度，点选卡牌以丢弃并重抽一张，点选finish discarding可跳过调度(没有动画或点击特效)
     6. 接着由敌方调度，同样需由使用者操作，点选finish discarding可跳过调度(没有动画或点击特效)
     7. 游戏开始，我方先出牌。选取卡牌再选取打出位置即可打出，打出后直接轮到对方
     8. 每方每次有30秒时间出牌，时间到未出则跳过换对方，右下角显示剩余时间
     9. 所有卡牌都没有技能
     10. ”效果牌”无法被打出
     11. 点选Passed可放弃跟牌(没有动画或点击特效)
     12. 某方赢得两 round后，游戏结束，自动退回首页
     13. 每round皆由我方先调度、先出牌

## 4. 参考数据
	1. Qt Documentation. (n.d.). Retrieved September 15, 2017, from http://doc.qt.io/
	2. Stack Overflow - Where Developers Learn, Share, & Build Careers. (n.d.). Retrieved September 15, 2017, from https://stackoverflow.com/

    
