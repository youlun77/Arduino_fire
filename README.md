# Arduino_fire
嵌入式微處理機專題
使用ESP32開發版加上火焰偵測器結合Line API


# arduino和esp32比較:
><img src="https://user-images.githubusercontent.com/121109511/211549990-af897440-68f1-41b1-9b42-6afc22115ea9.png" width="50%" height="50%"/>
使用esp32主要是為了wifi功能  
透過wifi來連接line notify API


# 實照
><img src="https://user-images.githubusercontent.com/121109511/211550957-26b5f7cd-911b-41eb-99a5-4739ce39fd5a.png" width="50%" height="50%"/>
左邊為火焰感測器，右邊為ESP32  


# 接線
><img src="https://user-images.githubusercontent.com/121109511/211553542-55531921-ced0-4538-894c-ff05c4d4f1fc.png" width="50%" height="50%"/>
偵測到火焰的時候，LED會亮起，同時ESP32透過line notify通知手機


# 驅動
><img src="https://user-images.githubusercontent.com/121109511/211554497-76f1767b-9e7c-4607-a3d3-942e8774236b.png" width="50%" height="50%"/>
驅動使用1.0.4版


# line notify API
><img src="https://user-images.githubusercontent.com/121109511/211552291-0c4341c2-10d6-4c16-b859-d9d71176a0a5.png" width="50%" height="50%"/>
><img src="https://user-images.githubusercontent.com/121109511/211552400-dd15d462-3119-466e-bd65-b3a6c050d737.png" width="50%" height="50%"/>
><img src="https://user-images.githubusercontent.com/121109511/211552417-a54845d2-cc85-4047-80dc-220055d9c9dc.png" width="50%" height="50%"/>
需到[line](https://notify-bot.line.me/zh_TW/)申請權杖


# 注意事項
第行的client.setInsecure()是為了繞過SSL憑證
[詳細可看](https://hackmd.io/@meebox/BJM_txyid)

