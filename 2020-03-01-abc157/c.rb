n, m = gets.chomp.split.map(&:to_i)

js = []
m.times do
  js.push gets.chomp.split.map(&:to_i)
end

ng = true
0.upto(999) do |x|
  f = true
  xs = x.to_s
  next if xs.size != n

  js.each do |s, c|
    if xs.size < s
      f = false
      break
    end
    if xs[s-1] != c.to_s
      f = false
      break
    end
  end

  if f
    ng = false
    puts x
    break
  end
end

if ng
  puts -1
end
