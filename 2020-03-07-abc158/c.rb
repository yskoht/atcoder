a, b = gets.chomp.split.map(&:to_i)

res = -1
(1..1100).each do |i|
  if (i * 0.08).floor == a && (i * 0.1).floor == b
    res = i
    break
  end
end

puts res