local mypkg = require("simpleCanvas")

w = 500
h = 400
local sum = mypkg.canvas(w, h)
print("Sum:", sum)

mypkg.pen(1,2.0)
mypkg.penDashed(true)
mypkg.rect(5, 5, w-10, h-10) -- XYWH
mypkg.penDashed(false)

mypkg.pen(2, 1.0) -- color, thickness
mypkg.rect(20, 40, 80, 60) -- overlapping

n = 45
f = 4
fr = f * 2 * math.pi -- radians
a = 40
for i = 1,n,1
do
  --mypkg.rect(i*40,i*5+20, 30,40)

  color = math.fmod(i,6)
  mypkg.pen(color+1, 3.0)

  angle = fr*i/n -- in radians
  mypkg.line(i*w/n, a*math.sin(angle)+h/2, w/n, 0) -- x y dx dy

  mypkg.labelRelative(0,0, i.."/"..color)
end

x=150
y=50
mypkg.pen(1, 1.0)
mypkg.line(x,y,100,0)
mypkg.labelSize(28)
mypkg.labelRelative(0,0, "At 150,50 😀 \u{4e2d} ♯ ♭")

--local greeting = "Test Unicode \u{1F600} \u{4E2D} \u{266f} \u{266d}" -- 😀 中 sharp flat
--print(greeting)

mypkg.save("temp/image9.png")


