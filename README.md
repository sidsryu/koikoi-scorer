# koikoi-scorer

[![Build Status](https://travis-ci.org/sidsryu/koikoi-scorer.svg?branch=master)][travis]
[![license](https://img.shields.io/github/license/mashape/apistatus.svg?maxAge=2592000)][license]

Koi-Koi score calculator for c++14

[license]: https://github.com/sidsryu/koikoi-scorer/blob/master/LICENSE 
[travis]: https://travis-ci.org/sidsryu/koikoi-scorer


## About Koi-Koi

코이코이는 화투패를 가지고 하는 일본 놀이로 한국의 고스톱과 비슷합니다. 
간단하고 예외가 적은 규칙이 점수 계산기를 구현하기에 적당히 재밌어보여 만들어봅니다.


## Installation

테스트 프레임워크로 [CppUTest][cpputest]를 사용합니다.
포함된 VS2015 프로젝트에서는 `/lib/cpputest` 위치에서 정적 라이브러리를 찾습니다. 
CppUTest는 수동으로 설치해야합니다.

CMake를 사용할 경우 CppUTest까지 함께 설치합니다.

```
cd build
cmake ..
make
```

[cpputest]: https://github.com/cpputest/cpputest


## Usage

플레이어마다 별도의 점수 계산기를 만듭니다. 매 획득 카드를 입력해줍니다. 점수 확인이 필요할때면, `total()` 함수로 알아낼 수 있습니다.

```c++
#include "koikoi-scorer.h"
#include "card-define.h"

KoikoiScorer player1;
KoikoiScorer player2;

player1.take(Card::PineBright);
player1.take(Card::PinePlain2);
player1.take(Card::CherryRibbon);
player1.take(Card::CherryPlain1);

player2.take(Card::PampasPlain1);
player2.take(Card::PampasPlain2);

...

auto score = palyer1.total();

```

또한 선택 규칙을 선별적으로 적용할 수 있습니다. 현재 지원가능한 모든 선택규칙의 기본값은 비활성화 상태입니다.

```c++
#include "koikoi-scorer.h"
#include "rule-define.h"

KoikoiScorer s;

s.addRule(Rule::SevenOrMoreDoubled);
s.addRule(Rule::SakeCupBothKindAndPlain);
s.addRule(Rule::ViewingTheFlower);
s.addRule(Rule::ViewingTheMoon);

...

auto score = s.total();
```

## Features

점수계산이 단순한 편인 낮은점수 규칙을 사용하기로 합니다.
낮은점수 규칙은 5광을 10점으로 계산합니다.
공식 설명서가 있는 닌텐도 규칙을 쓰기로 했습니다.

현재 목표로 잡고 있는 기본 규칙은 아래와 같습니다;

* [Nintendo rules][nintendo]

지원하는 선택 규칙은 다음과 같습니다;

* 7 or more points in total, score doubled.
* The sake cup(mums kind) to count a kind and a plain at the same time.
* 1 extra point for each additional ribbon after Red-Ribbons and/or Blue-Ribbons
* 1 extra point for each additional kind after Boar-Deer-Butterfly
* Viewing-the-Flower
* Viewing-the-Moon

[nintendo]: https://www.nintendo.co.jp/n09/hana-kabu_games/

## Koi-Koi Scoring Rules

### Instance Wins

* Four-Hands - 6 pts., begining hand has all four cards of the same suit.

    ![Pine Bright][11]![Pine Ribbon][12]![Pine Plain][13]![Pine Plain][14]

* Sticky - 6 pts., beginig hand has four pairs of cards of matching suits.

    ![Plum Ribbon][22]![Plum Plain][23]
    ![Wisteria Kind][41]![Wisteria Plain][44]
    ![Paulownia Plain][124]![Paulownia Plain][122]
    ![Pampas Bright][81]![Pampas Plain][84]

### Scoring Hands

* Five-Brights - 10 pts.

    ![Pine Bright][11]![Cherry Bright][31]![Pampas Bright][81]![Paulownia Bright][121]![Willow Bright][111]

* Four-Brights - 8 pts.

    ![Pine Bright][11]![Cherry Bright][31]![Pampas Bright][81]![Paulownia Bright][121]

* Three-Brights - 5 pts., any three brights without willow.

    ![Pine Bright][11]![Cherry Bright][31]![Pampas Bright][81]

* Viewing-the-Flower - 5 pts.

    ![Cherry Bright][31]![Mums Kind][91]

* Viewing-the-Moon - 5 pts.

    ![Pampas Bright][81]![Mums Kind][91]

* Boar-Deer-Butterfly - 5 pts.

    ![Clover Kind][71]![Maple Kind][101]![Peony Kind][61]

* Red-Ribbons - 5 pts., all three poetry ribbons.

    ![Pine Ribbon][12]![Plum Ribbon][22]![Cherry Ribbon][32]

* Blue-Ribbons - 5 pts., all three purple ribbons.

    ![Mums Ribbon][92]![Peony Ribbon][62]![Maple Ribbon][102]

* Kinds - 1 pt., five kinds. 1 extra pt. for each additional kind.
* Riboons - 1 pt., five ribbons. 1 extra pt. for each additional ribbon.
* Plains - 1 pt., ten plains. 1 extra pt. for each additional plain.

[11]: _image/11.png "Pine Bright"
[12]: _image/12.png "Pine Ribbon"
[13]: _image/13.png "Pine Plain"
[14]: _image/14.png "Pine Plain"
[21]: _image/21.png "Plum Kind"
[22]: _image/22.png "Plum Ribbon"
[23]: _image/23.png "Plum Plain"
[24]: _image/24.png "Plum Plain"
[31]: _image/31.png "Cherry Bright" 
[32]: _image/32.png "Cherry Ribbon"
[33]: _image/33.png "Cherry Plain"
[34]: _image/34.png "Cherry Plain"
[41]: _image/41.png "Wisteria Kind"
[42]: _image/42.png "Wisteria Ribbon"
[43]: _image/43.png "Wisteria Plain"
[44]: _image/44.png "Wisteria Plain"
[51]: _image/51.png "Iris Kind"
[52]: _image/52.png "Iris Ribbon"
[53]: _image/53.png "Iris Plain"
[54]: _image/54.png "Iris Plain"
[61]: _image/61.png "Peony Kind"
[62]: _image/62.png "Peony Ribbon"
[63]: _image/63.png "Peony Plain"
[64]: _image/64.png "Peony Plain"
[71]: _image/71.png "Clover Kind"
[72]: _image/72.png "Clover Ribbon"
[73]: _image/73.png "Clover Plain"
[74]: _image/74.png "Clover Plain"
[81]: _image/81.png "Pampas Bright"
[82]: _image/82.png "Pampas Kind"
[83]: _image/83.png "Pampas Plain"
[84]: _image/84.png "Pampas Plain"
[91]: _image/91.png "Mums Kind"  
[92]: _image/92.png "Mums Ribbon" 
[93]: _image/93.png "Mums Plain"
[94]: _image/94.png "Mums Plain"
[101]: _image/101.png "Maple Kind"
[102]: _image/102.png "Maple Ribbon"
[103]: _image/103.png "Maple Plain"
[104]: _image/104.png "Maple Plan"
[111]: _image/111.png "Willow Bright"
[112]: _image/112.png "Willow Kind"
[113]: _image/113.png "Willow Bribbon"
[114]: _image/114.png "Willow Plain"
[121]: _image/121.png "Paulownia Bright"
[122]: _image/122.png "Paulownia Plain"
[123]: _image/123.png "Paulownia Plain"
[124]: _image/124.png "Paulownia Plain"


## Licensing

This project is licensed under the terms of [the MIT licnese][license].

It is licensed under the terms of [the GNU General Public License][gpl], 
that all hanafuda images in the `_image` directory and the documents contain the images.
The images are files from [Wikimedia Commons][wikimedia].

[gpl]: https://www.gnu.org/licenses/gpl.html
[wikimedia]: https://commons.wikimedia.org/wiki/Category:SVG_Hanafuda
