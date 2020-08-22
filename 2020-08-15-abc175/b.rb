n = gets.to_i
l = gets.chomp.split.map(&:to_i)

cnt = 0

n.times do |a|
  (a+1).upto(n-1) do |b|
    (b+1).upto(n-1) do |c|
      x = l[a]
      y = l[b]
      z = l[c]

      if (x != y and y != z and z != x) and (x + y > z and x + z > y and y + z > x)
        cnt += 1
      end
    end
  end
end

puts cnt