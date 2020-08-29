s = gets.chomp
t = gets.chomp

ans = 10000

(s.size - t.size + 1).times do |i|
  cnt = t.size
  t.size.times do |k|
    cnt -= 1 if s[i + k] == t[k]
  end
  ans = [ans, cnt].min
end

puts ans
