require 'set'

n = gets.to_i

s = Set.new []
a = 2
while a * a <= n
  t = a * a
  while t <= n
    s.add(t)
    t *= a
  end
  a += 1
end

puts n - s.size
