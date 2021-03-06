n = gets.to_i
e = []
n.times do
  e.push gets.chomp.split.map(&:to_i)
end

res = 10 ** 6
e.each.with_index do |(a, _), i|
  e.each.with_index do |(_, b), j|
    t = (i == j) ? a + b : [a, b].max
    res = [res, t].min
  end
end

puts res
