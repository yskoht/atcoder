include Math

a, b, h, m = gets.chomp.split.map(&:to_f)

hour = 2.0 * Math::PI * ( (h * 60.0 + m) / (12.0 * 60.0) )
min = 2.0 * Math::PI * ( m / 60.0 )

hx = a * Math.cos(hour)
hy = a * Math.sin(hour)

mx = b * Math.cos(min)
my = b * Math.sin(min)

puts Math.sqrt((hx - mx) ** 2 + (hy - my) ** 2)
