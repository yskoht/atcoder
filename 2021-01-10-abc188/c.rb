n = gets.to_i
a = gets.chomp.split.map(&:to_i)

c = a.map.with_index{ |x, i| [i, x] }

(n-1).times do |k|
  b = []
  0.step(2**(n-k)-1, 2) do |i|
    x = c[i]
    y = c[i+1]
    z = x[1] > y[1] ? x : y
    b.push z
  end
  c = b
end

x = c[0]
y = c[1]

if x[1] > y[1]
  puts y[0] + 1
else
  puts x[0] + 1
end
