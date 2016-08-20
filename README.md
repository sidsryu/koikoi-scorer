# koikoi-scorer

[![Build Status](https://travis-ci.org/sidsryu/koikoi-scorer.svg?branch=master)][travis]
[![license](https://img.shields.io/github/license/mashape/apistatus.svg?maxAge=2592000)][license]

Koi-Koi score calculator.

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


## Features

점수계산이 단순한 편인 낮은점수 규칙을 사용하기로 합니다.
낮은점수 규칙은 5광을 10점으로 계산합니다.
공식 설명서가 있는 닌텐도 규칙을 쓰기로 했습니다.

현재 목표로 잡고 있는 기본 규칙은 아래와 같습니다;

* Nintendo default rules

만들 선택 규칙은 다음과 같습니다;

* 1 extra point for each additional ribbon after Red-Ribbons and/or Blue-Ribbons
* 1 extra point for each additional kind after Boar-Deer-Butterfly
* Rainy-Four-Brights
* Viewing-the-Flower
* Viewing-the-Moon
* The sake cup to count a kind and a plain at the same time.


## Koi-Koi Scoring Rules

![Pampas Bright][81] ![Chrysanthemum Animal][91]

> 작성중

[81]: _image/81.png "Pampas Bright"
[91]: _image/91.png "Chrysanthemum Animal"


## Licensing

This project is licensed under the terms of [the MIT licnese][license].

It is licensed under the terms of [the GNU General Public License][gpl], 
that all hanafuda images in the `_image` directory and the documents contain the images.
The images are files from [Wikimedia Commons][wikimedia].

[gpl]: https://www.gnu.org/licenses/gpl.html
[wikimedia]: https://commons.wikimedia.org/wiki/Category:SVG_Hanafuda
