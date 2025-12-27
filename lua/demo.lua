-- Usage: lua demo.lua "temp/image9.png"
local sc = require("simpleCanvas")

w = 500
h = 400
local sum = sc.canvas(w, h)
print("Sum:", sum)

sc.pen(1,2.0)
sc.penDashed(true)
sc.rect(5, 5, w-10, h-10) -- XYWH
sc.penDashed(false)

sc.pen(2, 1.0) -- color, thickness
sc.rect(20, 40, 80, 60) -- overlapping

n = 45 -- number of samples
f = 4 -- frequency
fr = f * 2 * math.pi -- radians
a = 40 -- amplitude
for i = 1,n,1
do
  color = math.fmod(i,6)
  sc.pen(color+1, 3.0)

  angle = fr*i/n -- in radians
  sc.line(i*w/n, a*math.sin(angle)+h/2, w/n, 0) -- x y dx dy

  sc.labelRelative(0,0, i.."/"..color)
end

x=150
y=50
sc.pen(1, 1.0)
sc.line(x,y,100,0)
sc.labelSize(28)
sc.labelRelative(0,0, "At 150,50 😀 \u{4e2d} ♯ ♭")

if arg[1] then
  sc.save(arg[1])
end