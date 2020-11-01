n = gets.to_i
p = []
n.times do
  p.push gets.chomp.split.map(&:to_i)
end

def cross (x1, y1, x2, y2)
  return (x1 * y2).to_f - (y1 * x2).to_f
end

def f(n, p)
  n.times do |i|
    x1, y1 = p[i]
    (i+1).upto(n-1) do |j|
      x2, y2 = p[j]
      (j+1).upto(n-1) do |k|
        x3, y3 = p[k]

        t = cross(x2 - x1, y2 - y1, x3 - x1, y3 - y1)
        d = -1e-8 <= t && t <= 1e-8
        return true if d
      end
    end
  end

  return false
end

if f(n, p)
  puts 'Yes'
else
  puts 'No'
end

