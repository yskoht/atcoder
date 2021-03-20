a, b = gets.chomp.split.map(&:to_i)
c, d = gets.chomp.split.map(&:to_i)

res = -100_000_000
a.upto(b) do |x|
  c.upto(d) do |y|
    res = [res, x - y].max
  end
end

puts res
