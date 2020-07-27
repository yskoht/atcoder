l, r, d = gets.chomp.split.map(&:to_i)

cnt = 0
l.upto(r) do |x|
  cnt += 1 if x % d == 0
end

puts cnt
