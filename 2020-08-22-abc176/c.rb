n = gets.to_i
a = gets.chomp.split.map(&:to_i)

ans = 0
prev = 0
a.each do |x|
  if prev > x
    t = prev - x
    ans += t
    prev = prev
  else
    prev = x
  end
end

puts ans