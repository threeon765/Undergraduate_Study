character p = new character(100, 100, 0.5);
character q = new character(600, 200, 0.7);
character r = new character(200, 500, 1);
Playerble a = new Playerble(50, 150, 180);
Playerble b = new Playerble(500, 210, 80);
Playerble c = new Playerble(300, 100, 210);
move m = new move(100, 100, 20);
move n = new move(400, 150, 10);
void setup() {
  size(1000, 1000);
  p.Mokoko();
  q.Mokoko();
  r.Mokoko();
  a.dr();   b.dr();   c.dr();
  m.bunny();   n.bunny();
}
class move {
  move() {   };
  move(float p, float q, float r) {
    x = p;      y = q;     d = r;
  }
  float x, y, d;
 void bunny() {
  noStroke();
  fill(255,255,255);
  ellipse(x, y, d*4.5, d*3.5);
  stroke(255, 200, 0);
  strokeWeight(d*0.05);
  fill(255, 220, 0);
  rect(x-d*0.50, y-d*0.30, d, d*0.67);
  stroke(0,0,0);
  strokeWeight(d*0.01);
  fill(255,160,0);
  beginShape() ;
  vertex(x+d*0.20, y+d*0.40);
  vertex(x, y+d*0.60);
  vertex(x-d*0.20, y+d*0.40);
  vertex(x+d*0.20, y+d*0.40);
  endShape() ;
  noFill();
  arc(x, y+d*0.75,d*1.30,d*0.50,0,PI);
  line(x, y+d*0.60, x, y+d);
  fill(0,0,0);
  ellipse(x-d*1.10, y, d*0.50, d*0.60);
  ellipse(x+d*1.10, y, d*0.50, d*0.60);
  fill(255,255,255);
  ellipse(x-d*1.10, y-d*0.13, d*0.30, d*0.30);
  ellipse(x+d*1.10, y-d*0.13, d*0.30, d*0.30);
  fill(255,0,0);
  ellipse(x+d*1.10, y+d*0.18, d*0.30, d*0.25);
  ellipse(x-d*1.10, y+d*0.18, d*0.30, d*0.25);
  noStroke();
  fill(255,255,255);
  ellipse(x-d*0.65, y-d*2.50, d*1.40, d*4);
  ellipse(x+d*0.65, y-d*2.50, d*1.40, d*4);
  stroke(2*d,2*d,2*d);
  line(x, y-d*1.75, x-d*0.01, y-d*3.30);
  noStroke();
  fill(255, 220, 0);
  ellipse(x+d*0.65, y-d*2.50, d*0.70, 2*d);
  ellipse(x-d*0.65, y-d*2.50, d*0.70, 2*d);
}
}
class Playerble {
  Playerble() {   };
  Playerble(float p, float q, float r) {
    x = p;      y = q;     d = r;
  }
  float x, y, d;
  void dr() {
    fill(#000000);
    circle(x, y, d);
    fill(#FFFFFF);
    circle(x, y, d/1.1);
    fill(#FFFFFF);
    circle(x-d/5, y-d/9, d/5);
    circle(x+d/5, y-d/9, d/5);
    fill(#000000);
    circle(x-d/5, y-d/9, d/10);
    circle(x+d/5, y-d/9, d/10);
    
    circle(x, y+d/5, d/5);
    fill(#FF0000);
    circle(x, y+d/5, d/5.5);
    
    noFill();
    stroke(10);
    
    
  }
}
class character{
  character(float a, float b, float c) { x = a;  y = b; s = c;  };
  float x, y, s;
  void Mokoko() {
    //모코코 오른쪽 머리 잎
    strokeWeight(s*7);
    fill(85,181,84);
    beginShape();
    vertex(s * 340 + x, s * 45 + y);
    bezierVertex(s*360+x,s*100+y, s*350+x,s*170+y, s*250+x,s*180+y);
    bezierVertex(s*240+x,s*140+y, s*240+x,s*100+y, s*290+x,s*80+y);
    bezierVertex(s*330+x,s*65+y, s*330+x,s*50+y, s*340+x,s*45+y);
    endShape();
    beginShape();
    vertex(s*250+x,s*180+y);
    bezierVertex(s*260+x,s*150+y, s*284+x,s*131+y, s*314+x,s*106+y);
    endShape();
    
    //모코코 왼쪽 머리 잎
    strokeWeight(s*7);
    fill(85,181,84);
    beginShape();
    vertex(s*100+x,s*130+y);
    bezierVertex(s*130+x,s*90+y, s*250+x,s*90+y, s*250+x,s*180+y);
    bezierVertex(200*s+x,200*s+y, 155*s+x,185*s+y, 140*s+x,160*s+y);
    bezierVertex(130*s+x,145*s+y, 120*s+x,135*s+y, 100*s+x,130*s+y);
    endShape();
    beginShape();
    vertex(250*s+x,180*s+y);
    bezierVertex(230*s+x,160*s+y, 190*s+x,140*s+y, 170*s+x,140*s+y);
    endShape();
    
    //모코코 얼굴
    //가운데 채울 삼각형
    strokeWeight(0);
    fill(196,237,137);
    triangle(111*s+x,379*s+y, 389*s+x,379*s+y, 250*s+x,161*s+y);
    //모코코 얼굴 외곽
    strokeWeight(s*7);
    fill(196,237,137);
    curve(25*s+x,405*s+y, 385*s+x,375*s+y, 250*s+x,165*s+y, 25*s+x,405*s+y);
    /*삼각형 오른쪽 윗변
    3:1 비율로 좌측 하단으로 내려갈수록 크기 up
    현재 90:30만큼 크기 키움*/
    strokeWeight(s*7);
    curve(250*s+x,71*s+y, 115*s+x,375*s+y, 385*s+x,375*s+y, 250*s+x,71*s+y);
    fill(196,237,137);
    /*삼각형 아랫변
    90:30 만큼 픽셀 늘림 5625 625 6250 79
    수학적으로 계산해서 111만큼 크기 키움*/
    strokeWeight(s*7);
    curve(475*s+x,405*s+y, 115*s+x,375*s+y, 250*s+x,165*s+y, 475*s+x,405*s+y); 
    fill(196,237,137);
    /*삼각형 왼쪽 윗변
    3:1 비율로 좌측 하단으로 내려갈수록 크기 up
    현재 75:25만큼 크기 키움*/
    
    //모코코 왼쪽 눈
    fill(0);
    strokeWeight(0);
    circle(190*s+x,316*s+y,42*s);
    fill(255);
    circle(195*s+x,310*s+y,14*s);
    //모코코 오른쪽 눈
    fill(0);
    circle(310*s+x,316*s+y,42*s);
    fill(255);
    circle(315*s+x,310*s+y,14*s);
    
    //모코코 왼쪽 홍조
    fill(255,148,180);
    circle(160*s+x,340*s+y,24*s);
    //모코코 오른쪽 홍조
    fill(255,148,180);
    circle(340*s+x,340*s+y,24*s);
    
    //모코코 입
    fill(255,148,180);
    strokeWeight(7*s);
    curve(250*s+x,230*s+y, 235*s+x,352*s+y, 265*s+x,352*s+y, 250*s+x,230*s+y);
    //모코코 왼쪽윗입술
    fill(196,237,137);
    strokeWeight(7*s);
    curve(240*s+x,330*s+y, 250*s+x,347*s+y, 230*s+x,352*s+y, 240*s+x,330*s+y);
    //모코코 오른쪽윗입술
    fill(196,237,137);
    strokeWeight(7*s);
    curve(260*s+x,330*s+y, 250*s+x,347*s+y, 270*s+x,352*s+y, 260*s+x,330*s+y);
    //모코코 혀 선
    strokeWeight(7*s);
    line(250*s+x,347*s+y, 250*s+x,356*s+y);
  }
}
