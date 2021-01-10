n = gets.to_i

ps = []
n.times do
  x, y = gets.chomp.split.map(&:to_i)
  ps.push [x, y]
end

cnt = 0
n.times do |i|
  (i+1).upto(n-1) do |k|
    x1, y1 = ps[i]
    x2, y2 = ps[k]

    a = (y2.to_f - y1.to_f) / (x2.to_f - x1.to_f)
    if -1.0 <= a && a <= 1.0
      cnt += 1
    end
  end
end

puts cnt