# 貓咪大戰爭/にゃんこ大戦争
[github](https://github.com/jueanc/OOPL2024s_project_CatsWar/tree/StillWork)
## 112-2 (Spring 2024) OOPL
This is an Object-Oriented Programming Labs (OOPL) team project being held at NTUT for the Spring semester 2024.

これは、2024年春学期に国立台北科技大学において開講される開催されるオブジェクト指向プログラミング実習(OOPL)のチームプロジェクトです。

## Team Members

```python
111590041 陳 珏安 CHEN, JUE AN 
109590061 高橋 鵬大 TAKAHASHI, Tomohiro
```

## Summary (概要)
Battle Cats (Battle Nekos) (ja: にゃんこ大戦争 / zh: 貓咪大戰爭)

> 這是一個塔防遊戲，玩家只要一邊的主塔血量歸零，便會被視為勝利或戰敗。
遊戲的遊玩方式非常簡單，玩家可以通過鍵盤左右鍵或滑鼠點擊上方的關卡按鈕來選擇要進入的關卡。進入關卡後，只需點擊右下方的「戰鬥開始」按鈕或按下 ENTER 鍵即可開始遊戲。

在關卡中，畫面下方會顯示玩家可以使用的貓咪角色，共有五個空格。舉第一關為例，進入關卡後只有第一個按鈕可以點擊，其他按鈕會被設為空格。左上方的金錢顯示了玩家的金錢數量，金錢可用於購買貓咪。點擊貓咪按鈕後，需要等待一段冷卻時間才能購買特定貓咪。金錢也可用於升級金錢生成的速度和上限，可以透過左下方的「LEVEL」按鈕升級，共有八個等級。

遊戲共有五個關卡。在第一關中，玩家可以使用一種貓咪，敵方也只會有一種怪物。隨著關卡的進展，玩家可以使用更多種類的貓咪，敵方也會新增更多種類的怪物。到了第五關，玩家可以使用五種貓咪，而敵方也會有五種怪物。

每種貓咪都有不同的攻擊傷害、血量、攻擊範圍和移動速度，類似於 DOTA 遊戲的角色設定。例如，射手的攻擊範圍較廣，但血量較低，此時需要坦克型的角色來幫助射手抵禦傷害。




## What we do (目前進度)

### Game UI (遊戲 UI)
- 完成遊戲封面及關卡選擇．Complete game cover and level selection.
### Gameplay Content (遊玩內容)
- 新增貓咪按鈕及CD的判斷．Added cat button and CD detection.
- 現在有五種貓．Now we have 5 types of cats.
- 現在有五種怪物．Now we have 5 types of monsters.
- 攻擊、擊退、死亡的判斷
- 金錢的計算





## 注意事項
- 在新增圖片時，不要使用複製圖片到資料夾的方式，這樣在程式中會報錯，無法正常執行，要用存檔的方式。

## Useful Reference
快速入門：https://lgf-readthedocs.readthedocs.io/zh_TW/latest/index.html
函式庫：https://ntut-xuan.github.io/LeistungsstarkesGameFramework
