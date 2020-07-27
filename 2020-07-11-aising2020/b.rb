n = gets.to_i
a = gets.chomp.split.map(&:to_i)

cnt = 0
a.each.with_index(1) do |x, i|
  cnt += 1 if i % 2 == 1 && x % 2 == 1
end

puts cnt
